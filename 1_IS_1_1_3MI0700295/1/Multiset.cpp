#include<fstream>
#include"Multiset.h"

#pragma warning (disable:4996)

namespace BitsetHelpers {

	unsigned powOfTwo(unsigned num) {

		unsigned mask = 1;
		return mask << num;
	}
	void setBits(unsigned start, unsigned end, unsigned& numCount, unsigned mask, uint8_t& bucket) {
		for (size_t i = start; i < end; i++)
		{
			if (numCount % 2 == 0) {
				bucket &= ~mask;
			}
			else {
				bucket |= mask;
			}
			mask <<= 1;
			numCount /= 2;
		}
	}
	void printNumber(unsigned num, unsigned occurencesOfNum) {
		for (unsigned i = 0; i < occurencesOfNum; i++) {
			std::cout << num << " ";
		}
	}
	void countOccurrences(unsigned start, unsigned end, unsigned& count, unsigned mask, uint8_t& bucket) {
		for (size_t i = start; i < end; i++)
		{
			if ((bucket & mask) == mask) {
				count += powOfTwo(i);
			}
			mask <<= 1;
		}
	}
}

using namespace BitsetHelpers;

unsigned Multiset::getBucketsCount() const {
	return (expression + BitsetConstants::BYTE_SIZE - 1) / BitsetConstants::BYTE_SIZE;
}

unsigned Multiset::getBucketInd(unsigned num) const {
	return  (((num + 1) * kBits + BitsetConstants::BYTE_SIZE - 1) / BitsetConstants::BYTE_SIZE) - 1;
}

unsigned Multiset::getStartIndex(unsigned num) const {

	unsigned shiftInd = ((num + 1) * kBits) % BitsetConstants::BYTE_SIZE;
	if (shiftInd == 0) {
		return 0;
	}
	return BitsetConstants::BYTE_SIZE - shiftInd;
}

unsigned Multiset::getMask(unsigned num) const {

	unsigned mask = 1;
	mask <<= getStartIndex(num);
	return mask;
}

unsigned Multiset::getNumberOccurrences(unsigned num) const {

	unsigned bucketInd = getBucketInd(num);
	unsigned startIndex = getStartIndex(num);

	uint8_t currBucket = buckets[bucketInd];
	unsigned mask = getMask(num);

	unsigned count = 0;

	unsigned takenPlacesInBucket = BitsetConstants::BYTE_SIZE - startIndex;

	if (takenPlacesInBucket < kBits) {

		countOccurrences(0, takenPlacesInBucket, count, mask, currBucket);

		uint8_t prevBucket = buckets[bucketInd - 1];

		mask = 1;

		countOccurrences(takenPlacesInBucket, kBits, count, mask, prevBucket);
	}

	else {
		countOccurrences(0, kBits, count, mask, currBucket);
	}

	return count;
}

void Multiset::addNumber(unsigned num) {

	unsigned occurrences = getNumberOccurrences(num);

	if (occurrences == powOfTwo(kBits) - 1) {
		return;
	}

	occurrences++;

	setCountOfOccurrences(occurrences, num);
}

void Multiset::printSet() const {
	std::cout << '{';
	for (unsigned i = 0; i <= maxNumber; i++)
	{
		unsigned occurrences = getNumberOccurrences(i);
		printNumber(i, occurrences);
	}
	std::cout << '}';
}

Multiset::Multiset(unsigned maxNumber, unsigned kBits) {
	this->maxNumber = maxNumber;
	this->kBits = kBits;
	this->expression = (maxNumber + 1) * kBits;
	this->countOfBuckets = getBucketsCount();

	buckets = new uint8_t[countOfBuckets];
	for (size_t i = 0; i < countOfBuckets; i++)
	{
		buckets[i] = 0;
	}
}

Multiset::Multiset(const Multiset& other) {
	copyFrom(other);
}

Multiset& Multiset::operator=(const Multiset& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Multiset::~Multiset() {
	free();
}

void Multiset::free() {
	delete[] buckets;
}

void Multiset::copyFrom(const Multiset& other) {
	maxNumber = other.maxNumber;
	kBits = other.kBits;
	expression = other.expression;
	countOfBuckets = other.countOfBuckets;
	buckets = new uint8_t[countOfBuckets]{ 0 };

	for (int i = 0; i < countOfBuckets; i++) {
		buckets[i] = other.buckets[i];
	}
}

void Multiset::setCountOfOccurrences(unsigned  numCount, unsigned num) {

	unsigned bucketInd = getBucketInd(num);
	unsigned startIndex = getStartIndex(num);

	uint8_t& currBucket = buckets[bucketInd];
	unsigned mask = getMask(num);

	unsigned takenPlacesInBucket = BitsetConstants::BYTE_SIZE - startIndex;

	if (takenPlacesInBucket < kBits) {

		setBits(0, takenPlacesInBucket, numCount, mask, currBucket);

		uint8_t& prevBucket = buckets[bucketInd - 1];
		mask = 1;

		setBits(takenPlacesInBucket, kBits, numCount, mask, prevBucket);

	}
	else {
		setBits(0, kBits, numCount, mask, currBucket);
	}
}

void Multiset::addNumberMultipleTimes(unsigned num, unsigned times) {

	unsigned maxOccurences = powOfTwo(kBits) - 1;

	if (times > maxOccurences) {
		times = maxOccurences;
	}

	for (unsigned i = 0; i < times; i++) {
		addNumber(num);
	}
}


Multiset setDifference(const Multiset& set1, const Multiset& set2) {

	Multiset res(set1.maxNumber, set1.kBits);

	for (unsigned i = 0; i <= set1.maxNumber; i++)
	{
		unsigned occurrencesInSet1 = set1.getNumberOccurrences(i);
		unsigned occurrencesInSet2 = set2.getNumberOccurrences(i);

		int totalOccurrences = occurrencesInSet1 - occurrencesInSet2;

		if (totalOccurrences < 0) {
			continue;
		}

		else {
			res.addNumberMultipleTimes(i, totalOccurrences);
		}
	}
	return res;
}


Multiset setIntersection(const Multiset& set1, const Multiset& set2) {

	assert(set1.kBits == set2.kBits);

	unsigned maxNumber = set1.maxNumber < set2.maxNumber ? set1.maxNumber : set2.maxNumber;
	unsigned kBits = set1.kBits;

	Multiset intersectionSet(maxNumber, kBits);

	for (unsigned i = 0; i <= maxNumber; i++)
	{
		unsigned occurrencesInSet1 = set1.getNumberOccurrences(i);
		unsigned occurrencesInSet2 = set2.getNumberOccurrences(i);
		unsigned totalOccurrences = occurrencesInSet1 < occurrencesInSet2 ? occurrencesInSet1 : occurrencesInSet2;

		if (totalOccurrences < 0)
			continue;

		intersectionSet.addNumberMultipleTimes(i, totalOccurrences);
	}

	return intersectionSet;
}

Multiset setComplement(const Multiset& set)
{
	Multiset res(set.maxNumber, set.kBits);

	unsigned totalOcc = powOfTwo(set.kBits) - 1;

	for (unsigned i = 0; i <= set.maxNumber; i++)
	{
		unsigned occurrencesInSet = set.getNumberOccurrences(i);

		if (occurrencesInSet == totalOcc) {
			continue;
		}

		else {
			res.addNumberMultipleTimes(i, totalOcc - occurrencesInSet);
		}

	}
	return res;
}


void Multiset::serialize(const char* toFile) const{

	std::ofstream ofs(toFile, std::ios::binary);

	if (!ofs.is_open()) {
		std::cout << "There was an error while openning the file for writing. " << std::endl;
		return;
	}

	ofs.write((const char*)&maxNumber, sizeof(unsigned));

	ofs.write((const char*)&kBits, sizeof(unsigned));

	ofs.write((const char*)&expression, sizeof(unsigned));

	ofs.write((const char*)&countOfBuckets, sizeof(unsigned));

	ofs.write((const char*)buckets, countOfBuckets * sizeof(uint8_t));

	ofs.close();
}

void Multiset::deserialize(const char* fromFile) {

	std::ifstream ifs(fromFile, std::ios::binary);

	if (!ifs.is_open()) {
		std::cout << "There was an error while openning the file for reading." << std::endl;
		return;
	}

	delete[] buckets;

	ifs.read((char*)&maxNumber, sizeof(unsigned));

	ifs.read((char*)&kBits, sizeof(unsigned));

	ifs.read((char*)&countOfBuckets, sizeof(unsigned));

	ifs.read((char*)&expression, sizeof(unsigned));

	buckets = new uint8_t[countOfBuckets];
	ifs.read((char*)buckets, countOfBuckets * sizeof(uint8_t));

	ifs.close();
}

void Multiset::printSetInBits() const {
	
	unsigned mask = 1;
	for (int bucketIndex = 0; bucketIndex < countOfBuckets; bucketIndex++) {

		for (int posInBucket = 7; posInBucket >= 0; posInBucket--) {
			std::cout << ((buckets[bucketIndex] >> posInBucket) & mask);
		}
		std::cout << " ";
	}
}

int main() {

}
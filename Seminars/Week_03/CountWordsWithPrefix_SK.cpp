#include<iostream>
#include<fstream>

#pragma warning (disable : 4996)

struct Word{

	char data[25]{};
	size_t density = 0;
};

size_t getFilezSize(std::ifstream& ifs) {

	unsigned currPos = ifs.tellg();
	ifs.seekg(0,std::ios::end);

	size_t fileSize = ifs.tellg();
	ifs.seekg(currPos);

	return fileSize;
}

bool isPrefix(const char* str1, const char* str2) {

	while (*str1 && *str2 && *str1 == *str2) {
		str1++;
		str2++;
	}
	return (*str1 == '\0');
}

void countMatchingPrefixes(const char* pref, const Word* words, size_t sizeWordArr,size_t& countMatches) {

	if (!pref || !words)
		return;

	for (size_t i = 0; i < sizeWordArr; i++) {
		if (isPrefix(pref, words[i].data))
			countMatches += words[i].density;
	}
	
}
size_t getScore(const char* pref, const char* fromFile) {

	if (!pref || !fromFile)
		return 0;

	std::ifstream ifs(fromFile,std::ios::binary);
	if (!ifs.is_open())
		return 0;

	size_t wordsCount = getFilezSize(ifs) / sizeof(Word);

	Word* myWords = new Word[wordsCount];
	ifs.read((char*)myWords, wordsCount * sizeof(Word));

	size_t countMatches = 0;

	countMatchingPrefixes(pref, myWords, wordsCount, countMatches);

	delete[] myWords;

	return countMatches;
}

void writeToFile(const char* toFile,const Word* words,size_t sizeWordArr) {

	if (!toFile || !words)
		return;

	std::ofstream ofs(toFile, std::ios::binary);
	if (!ofs.is_open())
		return;

	ofs.write((const char*)words, sizeof(Word) * sizeWordArr);
}

int main() {

	Word words[3];
	words[0] = { "FMI",4 };
	words[1] = { "home",1 };
	words[2] = { "hotel",7 };

	writeToFile("CountPrefixes.dat", words, 3);
	std::cout << getScore("ho", "CountPrefixes.dat");


}

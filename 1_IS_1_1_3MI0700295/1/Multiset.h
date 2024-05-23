#pragma once
#include <iostream>
#include <assert.h>

//HELPER SOURCES: https://github.com/desiish/OOP_Pract_2023_2024/tree/main/Pract06/Multiset

namespace BitsetConstants {
    constexpr unsigned BYTE_SIZE = sizeof(uint8_t)* 8;
}

namespace BitsetHelpers {
   unsigned powOfTwo(unsigned num);
   void setBits(unsigned start, unsigned end, unsigned& numCount, unsigned mask, uint8_t& bucket);
   void printNumber(unsigned num, unsigned occurrencesOfNum);
   void countOccurrences(unsigned start, unsigned end, unsigned& count, unsigned mask, uint8_t& bucket);
}

class Multiset {

    uint8_t* buckets = nullptr;
    unsigned maxNumber = 0;
    unsigned kBits = 0;
    unsigned countOfBuckets = 0;
    unsigned expression = 0;
   

    void free();
    void copyFrom(const Multiset& other);

    unsigned getBucketsCount() const;
    unsigned getBucketInd(unsigned num) const;
    unsigned getStartIndex(unsigned num) const;
    unsigned getMask(unsigned num) const;

public:
    Multiset() = default;
    Multiset(unsigned n, unsigned k);
    Multiset(const Multiset& other);
    Multiset& operator=(const Multiset& other);
    ~Multiset();

    void addNumberMultipleTimes(unsigned num, unsigned times);
    void addNumber(unsigned num);

    unsigned getNumberOccurrences(unsigned num) const;
    void setCountOfOccurrences(unsigned numCount, unsigned num);

    void printSet() const;
    void printSetInBits() const;

    friend Multiset setIntersection(const Multiset& set1, const Multiset& set2);
    friend Multiset setDifference(const Multiset& set1, const Multiset& set2);
    friend Multiset  setComplement(const Multiset& set);

    void serialize(const char* toFile) const;
    void deserialize(const char* fromFile);

};

    
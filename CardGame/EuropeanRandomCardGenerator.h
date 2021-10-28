#pragma once

#include "GenericRandomCardGenerator.h"
#include "EuropeanSuites.h"
#include "EuropeanRanks.h"

class EuropeanRandomCardGenerator : public GenericRandomCardGenerator {
public:
    EuropeanRandomCardGenerator() {
        GenericSuites = new EuropeanSuitePackage();
        GenericRanks = new EuropeanRankPackage();
    }

    ~EuropeanRandomCardGenerator() {

    }

};

class GenericRandomCardGenerator {
public:
    virtual ~GenericRandomCardGenerator() = 0;

    bool UniqueCardsExist() const;

    GenericCard* GetRandomCard() const;
    Card GetUniqueRandomCard();

    int SetNumOfCardSets(unsigned int num) { NumOfCardSets = num; }
    void GenerateNewSeed();
    void ClearHistory();

protected:
    GenericSuitePackage* GenericSuites;
    GenericRankPackage* GenericRanks;

    unsigned int NumOfCardSets;

    std::unordered_map<int, int> CardHistory;
    GenericCard* GetRandomCardFromVal(int val) const;
};
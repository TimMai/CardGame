#pragma once

#include <unordered_map>
#include "Card.h"
#include "GenericRank.h"
#include "GenericSuite.h"

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

class RandomCardGenerator {
public:
    RandomCardGenerator();
    ~RandomCardGenerator();

    bool UniqueCardsExist() const;

    Card GetRandomCard() const;
    Card GetUniqueRandomCard();

    void GenerateNewSeed();

    void ClearHistory();

private:
    static const int NUM_SUITES = (int)Card::Suite_t::NumSuites_t;
    static const int NUM_RANKS = (int)Card::Rank_t::NumRanks_t;
    static const int NUM_COMBINATIONS = NUM_SUITES * NUM_RANKS;

    std::unordered_set<int> CardHistory;

    Card GetRandomCardFromVal(int val) const;
};

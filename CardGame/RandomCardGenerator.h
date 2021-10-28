#pragma once

#include <unordered_set>
#include "Card.h"

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
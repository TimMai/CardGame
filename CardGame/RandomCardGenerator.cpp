#include "RandomCardGenerator.h"
#include <stdexcept>
#include <time.h>


RandomCardGenerator::RandomCardGenerator() {
    srand(time(NULL));
}

RandomCardGenerator::~RandomCardGenerator() {
}


void RandomCardGenerator::GenerateNewSeed() {
    srand(time(NULL));
}

bool RandomCardGenerator::UniqueCardsExist() const {
    return CardHistory.size() != NUM_COMBINATIONS;
}

Card RandomCardGenerator::GetRandomCard() const {
    int RandomVal = rand() % NUM_COMBINATIONS;

    return GetRandomCardFromVal(RandomVal);
}

Card RandomCardGenerator::GetUniqueRandomCard() {
    if (!UniqueCardsExist())
        throw std::logic_error("No more unique cards exist");

    
    int RandomVal = rand() % NUM_COMBINATIONS;

    //* Crude unique random card generation
    while (CardHistory.find(RandomVal) != CardHistory.end()) {
        RandomVal++;

        if (RandomVal == NUM_COMBINATIONS)
            RandomVal = 0;
    }

    CardHistory.insert(RandomVal);
    return GetRandomCardFromVal(RandomVal);
}

void RandomCardGenerator::ClearHistory() {
    CardHistory.clear();
}

Card RandomCardGenerator::GetRandomCardFromVal(int val) const {
    Card::Suite_t RandomSuite = (Card::Suite_t)(val / (NUM_COMBINATIONS / NUM_SUITES));
    Card::Rank_t RandomRank = (Card::Rank_t)(val % (NUM_COMBINATIONS / NUM_SUITES));

    return Card(RandomSuite, RandomRank);
}
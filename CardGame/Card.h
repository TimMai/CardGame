#pragma once

#include <string>
#include "GenericSuite.h"
#include "GenericRank.h"

class GenericCard {
public:
    GenericCard() : GenericCard(NULL, NULL) {
    }

    GenericCard(GenericSuite* Suite, GenericRank* Rank) {
        this->Suite = Suite;
        this->Rank = Rank;
    }

    ~GenericCard() {
        if (Suite)
            delete Suite;
        if (Rank)
            delete Rank;
    }

    const GenericSuite* GetSuite() const { return (const GenericSuite*)Suite; }
    const GenericRank* GetRank() const { return (const GenericRank*)Rank; }

    std::string ToString() const { return Rank->ToString() + " of " + Suite->ToString(); }

protected:
    GenericSuite* Suite;
    GenericRank* Rank;
};


class Card {
public:
    enum class Suite_t {
        Spades_t,
        Clubs_t,
        Diamonds_t,
        Hearts_t,
        NumSuites_t
    };

    enum class Rank_t {
        Ace_t,
        Two_t,
        Three_t,
        Four_t,
        Five_t,
        Six_t,
        Seven_t,
        Eight_t,
        Nine_t,
        Ten_t,
        Jack_t,
        Queen_t,
        King_t,
        NumRanks_t
    };


    Card() {}
    Card(Suite_t Suite, Rank_t Rank) {
        this->Suite = Suite;
        this->Rank = Rank;
    }

    ~Card() {}


    Suite_t GetSuite() { return Suite; }
    Rank_t GetRank() { return Rank; }

    void SetSuite(Suite_t Suite) { this->Suite = Suite; }
    void SetRank(Rank_t Rank) { this->Rank = Rank; }

private:
    Suite_t Suite;
    Rank_t Rank;
};


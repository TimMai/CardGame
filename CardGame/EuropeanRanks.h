#pragma once

#include "GenericRank.h"

class AceRank : public GenericRank {
public:
    AceRank() {
        Value = 1;
    }
    ~AceRank() {}

    std::string ToString() const { return "Ace"; }
};

class TwoRank : public GenericRank {
public:
    TwoRank() {
        Value = 2;
    }
    ~TwoRank() {}

    std::string ToString() const { return "Two"; }
};

class ThreeRank : public GenericRank {
public:
    ThreeRank() {
        Value = 3;
    }
    ~ThreeRank() {}

    std::string ToString() const { return "Three"; }
};

class FourRank : public GenericRank {
public:
    FourRank() {
        Value = 4;
    }
    ~FourRank() {}

    std::string ToString() const { return "Four"; }
};

class FiveRank : public GenericRank {
public:
    FiveRank() {
        Value = 5;
    }
    ~FiveRank() {}

    std::string ToString() const { return "Five"; }
};

class SixRank : public GenericRank {
public:
    SixRank() {
        Value = 6;
    }
    ~SixRank() {}

    std::string ToString() const { return "Six"; }
};

class SevenRank : public GenericRank {
public:
    SevenRank() {
        Value = 7;
    }
    ~SevenRank() {}

    std::string ToString() const { return "Seven"; }
};

class EightRank : public GenericRank {
public:
    EightRank() {
        Value = 8;
    }
    ~EightRank() {}

    std::string ToString() const { return "Eight"; }
};

class NineRank : public GenericRank {
public:
    NineRank() {
        Value = 9;
    }
    ~NineRank() {}

    std::string ToString() const { return "Nine"; }
};

class TenRank : public GenericRank {
public:
    TenRank() {
        Value = 9;
    }
    ~TenRank() {}

    std::string ToString() const { return "Ten"; }
};

class JackRank : public GenericRank {
public:
    JackRank() {
        Value = 10;
    }
    ~JackRank() {}

    std::string ToString() const { return "Jack"; }
};

class QueenRank : public GenericRank {
public:
    QueenRank() {
        Value = 12;
    }
    ~QueenRank() {}

    std::string ToString() const { return "Queen"; }
};

class KingRank : public GenericRank {
public:
    KingRank() {
        Value = 13;
    }
    ~KingRank() {}

    std::string ToString() const { return "King"; }
};


class EuropeanRankPackage : public GenericRankPackage {
public:
    enum {
        Ace,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
        NumOfRanks
    };

    EuropeanRankPackage() {
        RankCollection = {
            new AceRank(),
            new TwoRank(),
            new ThreeRank(),
            new FourRank(),
            new FiveRank(),
            new SixRank(),
            new SevenRank(),
            new EightRank(),
            new NineRank(),
            new TenRank(),
            new JackRank(),
            new QueenRank(),
            new KingRank()
        };
    }

    ~EuropeanRankPackage() {
        for (int i = 0; i < RankCollection.size(); i++) {
            delete RankCollection[i];
        }
    }
};

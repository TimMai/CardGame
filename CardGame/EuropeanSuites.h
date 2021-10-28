#pragma once

#include "GenericSuite.h"

class SpadesSuite : public GenericSuite {
public:
    SpadesSuite() {
        Value = 0;
    }
    ~SpadesSuite() {}

    std::string ToString() const { return "Spades"; }
};

class ClubsSuite : public GenericSuite {
public:
    ClubsSuite() {
        Value = 1;
    }
    ~ClubsSuite() {}

    std::string ToString() const { return "Clubs"; }
};

class DiamondsSuite : public GenericSuite {
public:
    DiamondsSuite() {
        Value = 2;
    }
    ~DiamondsSuite() {}

    std::string ToString() const { return "Diamonds"; }
};

class HeartsSuite : public GenericSuite {
public:
    HeartsSuite() {
        Value = 3;
    }
    ~HeartsSuite() {}

    std::string ToString() const { return "Hearts"; }
};

class EuropeanSuitePackage : public GenericSuitePackage {
public:
    enum {
        Spades,
        Clubs,
        Diamonds,
        Hearts,
        NumOfSuites
    };

    EuropeanSuitePackage() {
        SuiteCollection = {
            new SpadesSuite(),
            new ClubsSuite(),
            new DiamondsSuite(),
            new HeartsSuite()
        };
    }

    ~EuropeanSuitePackage() {
        for (int i = 0; i < NumOfSuites; i++) {
            delete SuiteCollection[i];
        }
    }
};
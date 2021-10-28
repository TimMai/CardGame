#pragma once

#include "Player.h"
#include "Card.h"
#include "RandomCardGenerator.h"

class ShreddingCardGameInterface {
public:

    virtual ~ShreddingCardGameInterface() = 0;

    virtual void SetUpGame() = 0;

    virtual void AddPlayer(Player player);


private:
    RandomCardGenerator generator;
};
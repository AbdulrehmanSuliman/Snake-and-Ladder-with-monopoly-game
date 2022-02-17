#pragma once
#include "Card.h"
#include "Grid.h"
#include"Snake.h"
class CardFour :public Card
{
public:
	CardFour(const CellPosition& pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardFour();
};
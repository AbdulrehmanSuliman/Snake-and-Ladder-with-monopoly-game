#pragma once
#include "Card.h"
#include"Ladder.h"
class CardThree :public Card
{
public:
	CardThree(const CellPosition& pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardThree();
};



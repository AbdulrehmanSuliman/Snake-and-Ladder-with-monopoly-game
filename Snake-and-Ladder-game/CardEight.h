#pragma once
#include "Card.h"
#include "ApplicationManager.h"
class CardEight :
	public Card
{
public:
	CardEight(const CellPosition& pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardEight();
};

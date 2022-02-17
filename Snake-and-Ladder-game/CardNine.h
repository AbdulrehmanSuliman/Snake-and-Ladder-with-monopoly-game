#pragma once
#include "Card.h"
class CardNine : public Card
{
	CellPosition ToGocell ;

public:
	CardNine(const CellPosition& pos);
	
	void ReadCardParameters(Grid * pGrid);

	void Apply(Grid* pGrid, Player* PPlayer);

	~CardNine();
};


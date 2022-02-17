#pragma once
#include "card.h"
#include"player.h"
class Card12 :	public Card
{
	

	
	 static Player* CardOwner;
	 static int CardValue;
	 static bool hasOwner;
	 static int Fees;
public:
	static int CountCard12;
	Card12(const CellPosition & pos); 
	
	virtual void ReadCardParameters(Grid * pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	
	



	virtual ~Card12(); 
};




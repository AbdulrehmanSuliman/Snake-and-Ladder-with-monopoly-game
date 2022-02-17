#pragma once
#include "card.h"
#include"player.h"
class Card11 :	public Card
{
	

	
	 static Player* CardOwner;
	 static int CardValue;
	 static bool hasOwner;
	 static int Fees;
public:
	static int CountCard11;
	Card11(const CellPosition & pos); 
	
	virtual void ReadCardParameters(Grid * pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	                                                  
	
	



	virtual ~Card11(); 
};





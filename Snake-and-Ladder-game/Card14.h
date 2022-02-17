#pragma once
#include "card.h"
#include"player.h"
class Card14 :	public Card
{
	

	
	 static Player* CardOwner;
	 static int CardValue;
	 static bool hasOwner;
	 static int Fees;
public:
	static int CountCard14;
	Card14(const CellPosition & pos); 
	
	virtual void ReadCardParameters(Grid * pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	                                                
	
	



	virtual ~Card14(); 
};





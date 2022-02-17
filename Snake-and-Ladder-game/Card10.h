#pragma once
#include "card.h"
#include"player.h"
class Card10 :	public Card
{


	
	 static Player* CardOwner;
	 static int CardValue;
	 static bool hasOwner;
	 static int Fees;
public:
	static int CountCard10;
	Card10(const CellPosition & pos); 
	
	virtual void ReadCardParameters(Grid * pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	                                                  
	
	



	virtual ~Card10(); // A Virtual Destructor
};






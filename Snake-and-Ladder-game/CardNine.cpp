#include "CardNine.h"



CardNine::CardNine(const CellPosition& pos) : Card(pos)
{
	cardNumber = 9;
}
void CardNine::ReadCardParameters(Grid * pGrid) {
	
	Input* pIn = pGrid->GetInput();

	pGrid->GetOutput()->PrintMessage("Choose The Cell, The Player Is Going To.. ");

	ToGocell = pIn->GetCellClicked(); //The cell the player will go to

	pGrid->GetOutput()->PrintMessage("(Done): The Cell Is Choosen Click Anywhere..");

	int a,b;

	pIn->GetPointClicked(a,b);   // Just To Give Time For User
	pGrid->GetOutput()->ClearStatusBar();
}

void CardNine:: Apply(Grid* pGrid, Player* PPlayer)

{
	Card::Apply(pGrid, PPlayer);

	pGrid->UpdatePlayerCell( PPlayer , ToGocell); // Updates the player Cellposition with the Choosen one

	pGrid->UpdateInterface();
	
}

CardNine::~CardNine()
{
}

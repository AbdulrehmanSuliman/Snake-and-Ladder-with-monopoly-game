#include "CardFive.h"
CardFive::CardFive(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 5;
}
void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	int X, Y;
	Card::Apply(pGrid, pPlayer);
	Input* pin;
	Output* pout;
	pin = pGrid->GetInput();
	pout = pGrid->GetOutput();
	pout->PrintMessage("New CardFive: Moves Forward the same number of steps you just rolled");
	pin->GetPointClicked(X, Y);
	CellPosition cellp(pPlayer->getdicenumber());
	pPlayer->Move(pGrid, pPlayer->getdicenumber());
}
CardFive:: ~CardFive()
{
}
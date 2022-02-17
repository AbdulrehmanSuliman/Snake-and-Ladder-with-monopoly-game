#include "CardSix.h"
CardSix::CardSix(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 6;
}
void CardSix::Apply(Grid* pGrid, Player* pPlayer)
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
	pPlayer->Move(pGrid, (-1) * (pPlayer->getdicenumber()));
}
CardSix:: ~CardSix()
{}
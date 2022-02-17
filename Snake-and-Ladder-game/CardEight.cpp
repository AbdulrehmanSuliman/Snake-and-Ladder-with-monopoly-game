#include "CardEight.h"
#include "RollDiceAction.h"
CardEight::CardEight(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 8;
}
void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int X, Y;
	Input* pin;
	Output* pout;
	pin = pGrid->GetInput();
	pout = pGrid->GetOutput();
	pout->PrintMessage("New Eight: Prevents the player from rolling the next turn");
	pin->GetPointClicked(X, Y);
	pPlayer->setCanPlay(false);
	pPlayer->setdicenumber(0);
	//RollDiceAction roll(pGrid);
	//roll.Execute();
	//pPlayer->setCanPlay(true);
}
CardEight:: ~CardEight() {}
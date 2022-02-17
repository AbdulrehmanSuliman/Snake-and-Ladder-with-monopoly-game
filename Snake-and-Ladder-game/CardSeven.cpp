#include "CardSeven.h"
#include "RollDiceAction.h"
CardSeven::CardSeven(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 7;
}
void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int X, Y;
	Input* pin;
	Output* pout;
	pin = pGrid->GetInput();
	pout = pGrid->GetOutput();
	pout->PrintMessage("New CardSeven: Gives the player another Dice Roll");
	pin->GetPointClicked(X, Y);


	RollDiceAction roll(pGrid);

	roll.Execute();
	for (int i = 0; i < 3; i++)
	{
		pGrid->AdvanceCurrentPlayer();
	}

}
CardSeven:: ~CardSeven() {}
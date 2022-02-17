#include "CardFour.h"
#include<iostream>
using namespace std;
CardFour::CardFour(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 4;
}
void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Input* pin;
	Output* pout;
	int X, Y;
	Card::Apply(pGrid, pPlayer);
	pin = pGrid->GetInput();
	pout = pGrid->GetOutput();
	pout->PrintMessage("New CardFour: Moves the player to the next Snake");
	pin->GetPointClicked(X, Y);
	pout->ClearStatusBar();
	CellPosition cellp(pPlayer->getstepcount());
	Snake* nextSnake;
	nextSnake = pGrid->GetNextSnake(cellp);

	if (nextSnake != NULL)
	{
		cellp = nextSnake->GetPosition();
		pPlayer->Move(pGrid, cellp.GetCellNum() - pPlayer->getstepcount()-1);
	}
}
CardFour::~CardFour()
{}
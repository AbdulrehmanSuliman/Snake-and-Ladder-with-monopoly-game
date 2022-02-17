#include "CardThree.h"
#include<iostream>
using namespace std;
CardThree::CardThree(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 3;
}
void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Input* pin;
	Output* pout;
	int X, Y;
	Card::Apply(pGrid, pPlayer);
	pin = pGrid->GetInput();
	pout = pGrid->GetOutput();
	pout->PrintMessage("New CardThree: Moves the player to the next ladder");
	pin->GetPointClicked(X, Y);
	pout->ClearStatusBar();
	CellPosition cellp(pPlayer->getstepcount());
	Ladder* nextladder;
	nextladder = pGrid->GetNextLadder(cellp);
	//Ladder*isthere = dynamic_cast<Ladder*>(nextladder);
	if (nextladder != NULL)
	{
		cellp = nextladder->GetPosition();
		pPlayer->Move(pGrid, cellp.GetCellNum() - pPlayer->getstepcount() - 1);
		//pGrid->UpdatePlayerCell(pPlayer, cellp);
	}
}
CardThree::~CardThree()
{}
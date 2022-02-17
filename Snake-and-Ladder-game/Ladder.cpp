#include "Ladder.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
	
	
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->GetOutput()->PrintMessage("you have reached a ladder.Click to continue");
	pGrid->GetInput()->GetUserAction();
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer,endCellPos);
	//    Review the "pGrid" functions and decide which function can be used for that
	
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}
 /*bool Ladder::IsOverLapping(GameObject*newobj)
 {
	 Ladder*pLadder=dynamic_cast<Ladder*>(newobj);
	 if(pLadder)
	 {
		 pLadder->GetPosition();
		 pLadder->GetEndPosition();	 
		 if((pLadder->GetEndPosition()).HCell()==(this->GetEndPosition()).HCell())
			 {
				 if((pLadder->GetEndPosition()).VCell()==(this->GetEndPosition()).VCell())
				 {
					 return true;
				 }
			 }
		 return false;
	 }
 }*/

Ladder::~Ladder()
{
}

#include "CutCardAction.h"
#include "CopyCardAction.h"
#include "ApplicationManager.h"
#include "AddSnakeAction.h"
#include "Snake.h"
#include "Grid.h"
#include "AddLadderAction.h"
#include "AddCardAction.h"
#include "RollDiceAction.h"
//#include "PasteCardAction.h"
#include "Card.h"

CutCardAction::CutCardAction(ApplicationManager *pApp):Action (pApp)
{

}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->PrintMessage("Click on The Cell to Save it ...");
	cutcell = pIn->GetCellClicked(); // The Cellposition of The Clicked Cell


	pOut->ClearStatusBar();

}

void CutCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

     ReadActionParameters();

  Card* Pcard = dynamic_cast< Card* >( pGrid->GetCellObject(cutcell) ); //Checking That The cell Has Card not Other objects "Won't return Null" 

  if(Pcard)

  {
	  
	  pGrid->SetClipboard(Pcard);  // Saves The Card Theat Pcard Pointing to

	  pGrid->RemoveObjectFromCell(cutcell);

	  pOut->PrintMessage("(Done): Cell Is Cutted Press To Continue ...");

	int a,b;
	pIn->GetPointClicked(a,b);   // Just To Give Time For User
	pGrid->GetOutput()->ClearStatusBar();

  }
  
  else
	 pGrid->PrintErrorMessage("Error: Cell already has another object ! Click to continue ...");

  pOut->ClearStatusBar();

}


CutCardAction::~CutCardAction(void)
{
}

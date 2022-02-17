#include "CopyCardAction.h"
#include "ApplicationManager.h"
#include "AddSnakeAction.h"
#include "Snake.h"
#include "Grid.h"
#include "AddLadderAction.h"
#include "AddCardAction.h"
#include "RollDiceAction.h"
#include "PasteCardAction.h"
#include "Card.h"


CopyCardAction::CopyCardAction(ApplicationManager *pApp): Action(pApp)
{

}

void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->PrintMessage("Click on The Cell to Save it ...");

	Copycell = pIn->GetCellClicked(); 

	pOut->PrintMessage("(Done): The Cell Is Saved And Copied Press To Continue...");
	
	int a,b;
	pIn->GetPointClicked(a,b);   // Just To Give Time For User
	pGrid->GetOutput()->ClearStatusBar();
	
}
void CopyCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

  ReadActionParameters();

  Card* Pcard =dynamic_cast< Card* >(pGrid->GetCellObject(Copycell)); //Checks IF the cell has a card Object OR nOt"NULL"

  if(Pcard)

	  pGrid->SetClipboard(Pcard);

  else

	 pGrid->PrintErrorMessage("Error: Cell already has another object ! Click to continue ...");


  pOut->ClearStatusBar();

  //............................................................................................................................
	//this->ReadActionParameters();

	//Cell* pCell=new Cell(firstcard);

	//Card* pCard=pCell->HasCard();

	//Grid * pGrid = pManager->GetGrid();
	//
	//if((pCard)!= NULL)
	//pGrid->SetClipboard(pCard);
	//else
	//	pGrid->PrintErrorMessage("Error: Cell already has another object ! Click to continue ...");

}



CopyCardAction::~CopyCardAction(void)
{
}

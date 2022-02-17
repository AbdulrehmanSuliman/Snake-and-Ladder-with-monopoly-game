#include "PasteCardAction.h"
#include "CopyCardAction.h"
#include "ApplicationManager.h"
#include "AddSnakeAction.h"
#include "Snake.h"
#include "Grid.h"
#include "AddLadderAction.h"
#include "AddCardAction.h"
#include "RollDiceAction.h"
#include "Card.h"


PasteCardAction::PasteCardAction(ApplicationManager *pApp) :Action (pApp)
{

}
void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pGrid->GetOutput()->PrintMessage("Click On The Cell You Wanna Paste to..");

	Newcell=pIn->GetCellClicked(); //Newcell is adata member


	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();

	Input* pIn = pGrid->GetInput();

	ReadActionParameters();

	int CardNumber= pGrid->GetClipboard()->GetCardNumber(); // Card Number Of Saved Card fl Clipboard

	Card* Pcard=new Card (Newcell); // Making a new Card with the choosen Cellposition

	Pcard->SetCardNumber(CardNumber); //Setting the new Card Number with the Saved One

	if(pGrid->AddObjectToCell(Pcard)) // Add el Object "Card" bl (Old Card Number and New Cellposition Choosen) + Checking lw fe Object fl cell
		
		    pGrid->AddObjectToCell(Pcard);

	else

		    pGrid->PrintErrorMessage("There Is An Object Choose another Cell");
	
	pGrid->GetOutput()->ClearStatusBar();



//	Grid* pGrid = pManager->GetGrid();
//
//	/*Input* pIn = pGrid->GetInput();*/
//
//	pGrid->GetOutput()->PrintMessage("Click on The Cell to Paste it ...");
//
//	Newcell = ((pGrid->GetInput())->GetCellClicked());


  //GameObject* Pobject =dynamic_cast< GameObject* >(pGrid->GetCellObject(Newcell));

  //pGrid->AddObjectToCell(pGrid->GetClipboard());
	
  //pOut->ClearStatusBar();

}
PasteCardAction::~PasteCardAction(void)
{
}
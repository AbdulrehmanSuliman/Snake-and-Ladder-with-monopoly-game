#include "NewGameAction.h"
#include "Player.h"
#include "GameObject.h"
NewGameAction::NewGameAction(ApplicationManager *pApp) : Action(pApp)
{
}
 void NewGameAction::ReadActionParameters()
 
 {	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Game Press To Continue ...");

	int a,b;
	pIn->GetPointClicked(a,b);   // Just To Give Time For User
	pGrid->GetOutput()->ClearStatusBar();
		
 }

	
 void NewGameAction::Execute()
 {
	 ReadActionParameters();

	 Grid* pGrid = pManager->GetGrid();

	 CellPosition* startCell=new CellPosition(8,0); //Intializes The CellPosition TO (8,0) " First Cell "

	for(int i=0;i<4;i++) // 3shan y3dy 3l 4 players

	{
		Player* PP =pGrid->GetCurrentPlayer(); // Returns The Current Player* "Turn"

		PP->SetWallet(100);

		pGrid->UpdatePlayerCell(PP,*startCell);

		PP->setstepcount(1);

		pGrid->AdvanceCurrentPlayer(); // Turn + 1

	}

		pGrid->UpdateInterface();
		
		pGrid->GetOutput()->CreatePlayModeToolBar(); //To Reset Values "Wallet etc.."
 }

NewGameAction::~NewGameAction(void)
{
}
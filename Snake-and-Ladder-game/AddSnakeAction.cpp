#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager *pApp) : Action(pApp)
{

}

void AddSnakeAction::ReadActionParameters()

{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Snake: Click on its Start Cell Up-->Down...");
	StartCell = pIn->GetCellClicked();

	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	EndCell = pIn->GetCellClicked();


	pOut->ClearStatusBar();

}


void AddSnakeAction::Execute()
{
	ReadActionParameters();

	Snake * pSnake = new Snake( StartCell , EndCell);
	Grid * pGrid = pManager->GetGrid(); 

	bool added = pGrid->AddObjectToCell(pSnake);

	if (!added)
	{
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
}


AddSnakeAction::~AddSnakeAction(void)
{
}

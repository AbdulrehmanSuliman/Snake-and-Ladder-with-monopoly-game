#include "DeleteAction.h"
#include "Grid.h"

DeleteAction::DeleteAction(ApplicationManager *pApp) : Action (pApp)
{

}
 void DeleteAction:: ReadActionParameters()
 {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on Cell you want to delete ...");

	delcell = pIn->GetCellClicked();

	pOut->ClearStatusBar();
 }
	
 void DeleteAction:: Execute()
 {
	 this->ReadActionParameters();

	 Grid* pGrid = pManager->GetGrid();

	 pGrid->RemoveObjectFromCell(delcell);

 }

DeleteAction::~DeleteAction(void)
{
}

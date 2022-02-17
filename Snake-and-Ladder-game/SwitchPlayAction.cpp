#include "SwitchPlayAction.h"
#include "Grid.h"

SwitchPlayAction::SwitchPlayAction(ApplicationManager* pApp): Action(pApp)
{
}

void SwitchPlayAction :: ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

}

void SwitchPlayAction :: Execute()
{
		this->ReadActionParameters();
		pOut->CreatePlayModeToolBar();

}

SwitchPlayAction::~SwitchPlayAction(void)
{
}

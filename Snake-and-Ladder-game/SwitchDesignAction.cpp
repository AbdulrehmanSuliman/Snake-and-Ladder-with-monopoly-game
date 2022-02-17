#include "SwitchDesignAction.h"
#include"Grid.h"

SwitchDesignAction::SwitchDesignAction(ApplicationManager *pApp) : Action(pApp)
{
}

void SwitchDesignAction :: ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

}

void SwitchDesignAction :: Execute()
{
this->ReadActionParameters();
pOut->CreateDesignModeToolBar();
}


SwitchDesignAction::~SwitchDesignAction(void)
{
}

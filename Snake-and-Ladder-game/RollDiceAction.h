#pragma once

#include "Action.h"

class RollDiceAction : public Action
{
	Grid* pGrid;
	// No parameters for this action

public:
	RollDiceAction(ApplicationManager *pApp);
	RollDiceAction(Grid*);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~RollDiceAction();
};


#pragma once
#include "action.h"
class CutCardAction : public Action
{
	CellPosition cutcell;

	/*CellPosition secondcard;*/

public:
	CutCardAction(ApplicationManager *pApp);

void ReadActionParameters();

void Execute();


	CutCardAction(void);
	~CutCardAction(void);
};


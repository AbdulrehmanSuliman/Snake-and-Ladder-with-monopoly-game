#pragma once
#include "action.h"
class CopyCardAction : public Action
{
	CellPosition Copycell;
	/*CellPosition secondcard;*/

public:
CopyCardAction(ApplicationManager *pApp);

virtual void ReadActionParameters();

virtual void Execute();


~CopyCardAction(void);
};


#pragma once
#include "action.h"
class AddSnakeAction :public Action
{
	CellPosition StartCell;
	CellPosition EndCell;

public:
	AddSnakeAction(ApplicationManager *pApp);
	void ReadActionParameters();

	void Execute();

	~AddSnakeAction(void);
};




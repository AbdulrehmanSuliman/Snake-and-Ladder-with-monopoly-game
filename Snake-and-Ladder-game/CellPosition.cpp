#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if(v>=0&&v<=8)
	{
		vCell=v;
		return true;
	}
	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if(h>=0&&h<=10)
	{
		hCell=h;
		return true;
	}

	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file
	if(hCell>=0&&vCell>=0&&hCell<=10&&vCell<=8)
	{
		return true;
	}
	return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{int cellnumber;
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file


cellnumber=cellPosition.HCell()-(11*cellPosition.VCell())+89;
if (cellPosition.IsValidCell())
{
	return cellnumber; // this line should be changed with your implementation
}
else return 0;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	CellPosition position;
	

	/// TODO: Implement this function as described in the .h file
	if (cellNum>0&&cellNum<100)
	{
		for(int h=0;h<11;h++)
	{
		for(int v=0;v<9;v++)
		{
		if((h-(11*v)+89)==cellNum)
			{
				position.SetHCell(h);
				position.SetVCell(v);
			}
		}
	}
	}
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	
	/// TODO: Implement this function as described in the .h file
	int CurrentCell;
	CurrentCell=hCell-(11*vCell)+89;
	int NewCell=addedNum+CurrentCell;
	for(int h=0;h<11;h++)
	{
		for(int v=0;v<9;v++)
		{
			if(NewCell==(h-(11*v)+89))
			{
				hCell=h;
				vCell=v;
			}
		}
	}


	// Note: this function updates the data members (vCell and hCell) of the calling object

}
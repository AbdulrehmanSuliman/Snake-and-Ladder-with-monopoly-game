#include "InputDiceAction.h"
#include"Grid.h"
#include"Player.h"

InputDiceAction::InputDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void InputDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void InputDiceAction::Execute()
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	Grid*pGrid=(pManager->GetGrid());

	bool Endded=pGrid->GetEndGame();

	// -- If not ended, do the following --:

	if(Endded==false)
	{

		pGrid->GetOutput()->PrintMessage("Enter Dice Value =");
		
		int Dice=(pGrid->GetInput())->GetInteger(pGrid->GetOutput()); //Gets The Entered Intger From The User

		int diceNumber;

		if(Dice>=1&&Dice<=6)
		{
			diceNumber=Dice;
		}
		else
		{
			diceNumber=0;
			pGrid->GetOutput()->PrintMessage("Invaild value ,Click to Continue....");
	
	        int a,b;
	          pGrid->GetInput()->GetPointClicked(a,b);   // Just To Give Time For User
	          pGrid->GetOutput()->ClearStatusBar();
		}

	// 3- Get the "current" player from pGrid

	Player*pPlayer=(pGrid->GetCurrentPlayer());

	// 4- Move the currentPlayer using function Move of class player
	
	pPlayer->Move(pGrid,diceNumber); // With The entered Amount
	
	// 5- Advance the current player number of pGrid

	if(Dice>=1&&Dice<=6)
	{
	pGrid->AdvanceCurrentPlayer();
    }

	pGrid->UpdateInterface();
	
	}
}

InputDiceAction::~InputDiceAction()
{

}
#include "Card10.h"
#include<cstring>

int Card10::CountCard10=0;
int Card10::CardValue=0;
bool Card10::hasOwner=false;
Player*Card10::CardOwner=NULL;
int Card10::Fees=0;
Card10::Card10(const CellPosition & pos) : Card(pos) 
{
	cardNumber = 10;
	CountCard10++;
}

Card10::~Card10(void)
{
}
void Card10::ReadCardParameters(Grid * pGrid)
{
	
	if(CountCard10==1)
	{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pin=pGrid->GetInput();
	Output *pout=pGrid->GetOutput();

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	int x,y;
	pout->PrintMessage("enter Card 10 Price=");
	pin->GetPointClicked(x,y);
	pout->ClearStatusBar();
	CardValue=pin->GetInteger(pout);
	pout->PrintMessage("Enter Fees to pay by passing player= ");
	Fees=pin->GetInteger(pout);

	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pout->ClearStatusBar();
	//CanEnterCvalue();
	
	}
}
void Card10::Apply(Grid* pGrid, Player* pPlayer)
{
	Input*pIn=pGrid->GetInput();
	Output*pOut=pGrid->GetOutput();
	Card::Apply(pGrid,pPlayer);
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	if(hasOwner==false)
	{
		pOut->PrintMessage("Do you want to buy that card Y/N");
		string ans=pIn->GetSrting(pOut);
		if (ans=="Y"||ans=="y")
		{
			if(pPlayer->GetWallet()>=CardValue)
			{
				pPlayer->SetWallet(pPlayer->GetWallet()-CardValue);
				CardOwner=pPlayer;
				hasOwner=true;
			}
			else
			{
				int x,y;
				pOut->PrintMessage("You don't Have Enough Coins,Click to continue.....");
				pIn->GetPointClicked(x,y);

			}

		}
	}
	else if(hasOwner==true)
		{
			if(pPlayer!=CardOwner)
			{
			
				pPlayer->SetWallet(pPlayer->GetWallet()-Fees);
				CardOwner->SetWallet(CardOwner->GetWallet()+Fees);
			}
			
		}
	
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number

			
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	
}



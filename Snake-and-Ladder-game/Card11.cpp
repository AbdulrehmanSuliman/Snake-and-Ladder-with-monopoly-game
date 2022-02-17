#include "Card11.h"
#include<cstring>

int Card11::CountCard11=0;
int Card11::CardValue=0;
bool Card11::hasOwner=false;
Player*Card11::CardOwner=NULL;
int Card11::Fees=0;
Card11::Card11(const CellPosition & pos) : Card(pos) 
{
	cardNumber = 11;
	CountCard11++;
}

Card11::~Card11(void)
{
}
void Card11::ReadCardParameters(Grid * pGrid)
{
	
	if(CountCard11==1)
	{
	
	Input* pin=pGrid->GetInput();
	Output *pout=pGrid->GetOutput();
	int x,y;
	pout->PrintMessage("enter Card 11 Price=");
	pin->GetPointClicked(x,y);
	pout->ClearStatusBar();
	CardValue=pin->GetInteger(pout);
	pout->PrintMessage("Enter Fees to pay by passing player= ");
	Fees=pin->GetInteger(pout);
	pout->ClearStatusBar();
	
	
	}
}
void Card11::Apply(Grid* pGrid, Player* pPlayer)
{
	Input*pIn=pGrid->GetInput();
	Output*pOut=pGrid->GetOutput();
	Card::Apply(pGrid,pPlayer);
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
}



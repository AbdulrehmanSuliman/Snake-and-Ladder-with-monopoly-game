#include "Card12.h"
#include<cstring>
int Card12::CountCard12=0;
int Card12::CardValue=0;
bool Card12::hasOwner=false;
Player*Card12::CardOwner=NULL;
int Card12::Fees=0;
Card12::Card12(const CellPosition & pos) : Card(pos) 
{
	cardNumber = 12;
	CountCard12++;
}

Card12::~Card12(void)
{
}
void Card12::ReadCardParameters(Grid * pGrid)
{
	
	if(CountCard12==1)
	{

	Input* pin=pGrid->GetInput();
	Output *pout=pGrid->GetOutput();

	int x,y;
	pout->PrintMessage("enter Card 12 Price=");
	pin->GetPointClicked(x,y);
	pout->ClearStatusBar();
	CardValue=pin->GetInteger(pout);
	pout->PrintMessage("Enter Fees to pay by passing player= ");
	Fees=pin->GetInteger(pout);
	pout->ClearStatusBar();
	
	}
}
void Card12::Apply(Grid* pGrid, Player* pPlayer)
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



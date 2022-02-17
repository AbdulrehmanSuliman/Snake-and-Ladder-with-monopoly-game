#include "Card14.h"
#include<cstring>

int Card14::CountCard14=0;
int Card14::CardValue=0;
bool Card14::hasOwner=false;
Player*Card14::CardOwner=NULL;
int Card14::Fees=0;
Card14::Card14(const CellPosition & pos) : Card(pos) 
{
	cardNumber = 14;
	CountCard14++;
}

Card14::~Card14(void)
{
}
void Card14::ReadCardParameters(Grid * pGrid)
{
	
	if(CountCard14==1)
	{
	
	

	


	
	Input* pin=pGrid->GetInput();
	Output *pout=pGrid->GetOutput();

	
	int x,y;
	pout->PrintMessage("enter Card 14 Price=");
	pin->GetPointClicked(x,y);
	pout->ClearStatusBar();
	CardValue=pin->GetInteger(pout);
	pout->PrintMessage("Enter Fees to pay by passing player= ");
	Fees=pin->GetInteger(pout);

	
	pout->ClearStatusBar();
	
	
	}
}
void Card14::Apply(Grid* pGrid, Player* pPlayer)
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



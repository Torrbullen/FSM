#include "Miner.h"
#include "Shopping.h"
#include <iostream>


void Shopping::Enter(Miner* pMiner) 
{
	std::cout << (pMiner->GetID()) << ": " << "has arrived at the shopping mall\n";
}

void Shopping::Execute(Miner* pMiner) 
{
	for (int i = 0; i < 5; i++)
	{
		if (pMiner->GetGold() >= pMiner->GetUpgrade(i).price && !pMiner->GetUpgrade(i).bIsBought)
			pMiner->PurchaseCertificate(i);
	}
	pMiner->movedelay++;
}

void Shopping::Exit(Miner* pMiner)
{
	std::cout << (pMiner->GetID()) << ": " << "is exiting the shopping mall\n";
}

const char* Shopping::Statename()
{
	const char* Statename = new char;
	Statename = "browsing wares";
	return Statename;
}
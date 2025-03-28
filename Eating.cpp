#include "Miner.h"
#include "Eating.h"
#include <iostream>


void Eating::Enter(Miner* pMiner) 
{
	if (std::strcmp(pMiner->GetLocation().c_str(), "restaurant")) 
	{
		std::cout << "\n" << (pMiner->GetID()) << ": " << "arrived at the restaurant.\n";
		pMiner->ChangeLocation("restaurant");
	}
}

void Eating::Execute(Miner* pMiner) 
{
	if (pMiner->GetUpgrade(3).bIsBought)
		pMiner->incrHunger(4);
	else
		pMiner->incrHunger(2);
}

void Eating::Exit(Miner* pMiner)
{
	std::cout << (pMiner->GetID()) << ": is leaving restaurant.\n";
}

const char* Eating::Statename()
{
	const char* Statename = new char;
	Statename = "eating";
	return Statename;
}
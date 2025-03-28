#include "Miner.h"
#include "Drinking.h"
#include <iostream>


void Drinking::Enter(Miner* pMiner) 
{
	if (std::strcmp(pMiner->GetLocation().c_str(), "bar")) 
	{
		std::cout << "\n" << (pMiner->GetID()) << ": " << "arrived at the bar.\n";
		pMiner->ChangeLocation("bar");
	}

}

void Drinking::Execute(Miner* pMiner) 
{
	if (pMiner->GetUpgrade(2).bIsBought)
		pMiner->incrThirst(5);
	else
		pMiner->incrThirst(3);
}

void Drinking::Exit(Miner* pMiner)
{
	std::cout << (pMiner->GetID()) << ": is leaving bar.\n";
}

const char* Drinking::Statename()
{
	const char* Statename = new char;
	Statename = "drinking";
	return Statename;
}
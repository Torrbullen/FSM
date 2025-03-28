#include "Mining.h"
#include "Miner.h"
#include <iostream>


void Mining::Enter(Miner* pMiner)
{
	if (std::strcmp(pMiner->GetLocation().c_str(), "goldmine"))
	{
		std::cout << (pMiner->GetID()) << ": " << "arrived at the gold mine\n";
		pMiner->ChangeLocation("goldmine");
	}
}

void Mining::Execute(Miner* pMiner) 
{
	if (pMiner->GetUpgrade(0).bIsBought)
		pMiner->incrGold(8);
	else
		pMiner->incrGold(4);
}

void Mining::Exit(Miner* pMiner)
{
	std::cout << (pMiner->GetID()) << ": is leaving mine\n";
}

const char* Mining::Statename()
{
	const char* Statename = new char;
	Statename = "mining";
	return Statename;
}

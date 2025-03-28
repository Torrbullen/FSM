#include "Lumbering.h"
#include "Miner.h"
#include <iostream>


void Lumbering::Enter(Miner* pMiner)
{
	if (std::strcmp(pMiner->GetLocation().c_str(), "forest"))
	{
		std::cout << (pMiner->GetID()) << ": " << "arrived at the forest\n";
		pMiner->ChangeLocation("forest");
	}
}

void Lumbering::Execute(Miner* pMiner)
{
	if (pMiner->GetUpgrade(0).bIsBought)
		pMiner->incrGold(8);
	else
		pMiner->incrGold(4);
}

void Lumbering::Exit(Miner* pMiner)
{
	std::cout << (pMiner->GetID()) << ": is leaving the forest\n";
}

const char* Lumbering::Statename()
{
	const char* Statename = new char;
	Statename = "lumbering";
	return Statename;
}
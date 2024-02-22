#include "Mining.h"
#include "Miner.h"
#include <iostream>


void Mining::Enter(Miner* pMiner) {
	if (std::strcmp(pMiner->GetLocation().c_str(), "goldmine")) {
		std::cout << "\n" << (pMiner->GetID()) << ": " << "is walking to the gold mine";
		pMiner->ChangeLocation("goldmine");
	}
}

void Mining::Execute(Miner* pMiner) {
	std::cout << "mining";
	pMiner->incrGold();
}

void Mining::Exit(Miner* pMiner)
{
	std::cout << "leaving mine";
}

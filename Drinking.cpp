#include "Miner.h"
#include "Drinking.h"
#include <iostream>


void Drinking::Enter(Miner* pMiner) {
	if (std::strcmp(pMiner->GetLocation().c_str(), "bar")) {
		std::cout << "\n" << (pMiner->GetID()) << ": " << "is walking to the bar. \n";
		pMiner->ChangeLocation("bar");
	}

}

void Drinking::Execute(Miner* pMiner) {
	std::cout << "drinking";
	pMiner->incrThirst(4);
}

void Drinking::Exit(Miner* pMiner)
{
	std::cout << "leaving bar. \n";
}

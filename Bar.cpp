#include "Miner.h"
#include "Bar.h"
#include <iostream>


void Bar::Enter(Miner* pMiner) {
	if (std::strcmp(pMiner->GetLocation().c_str(), "bar")) {
		std::cout << "\n" << (pMiner->GetID()) << ": " << "is walking to the bar. \n";
		pMiner->ChangeLocation("bar");
	}
}

void Bar::Execute(Miner* pMiner) {
	std::cout << "drinking";
	pMiner->incrThirst(3);
}

void Bar::Exit(Miner* pMiner)
{
	std::cout << "leaving bar. \n";
}

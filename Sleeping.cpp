#include "Miner.h"
#include "Sleeping.h"
#include <iostream>


void Sleeping::Enter(Miner* pMiner) {
	if (std::strcmp(pMiner->GetLocation().c_str(), "home")) {
		std::cout << "\n" << (pMiner->GetID()) << ": " << "is walking to the home. \n";
		pMiner->ChangeLocation("home");
	}
	
}

void Sleeping::Execute(Miner* pMiner) {
	std::cout << "Sleeping";
	pMiner->incrFatigue(3);
}

void Sleeping::Exit(Miner* pMiner)
{
	std::cout << "leaving home. \n";
}
#include "Miner.h"
#include "Eating.h"
#include <iostream>


void Eating::Enter(Miner* pMiner) {
	if (std::strcmp(pMiner->GetLocation().c_str(), "restaurant")) {
		std::cout << "\n" << (pMiner->GetID()) << ": " << "is walking to the restaurant. \n";
		pMiner->ChangeLocation("restaurant");
	}

}

void Eating::Execute(Miner* pMiner) {
	std::cout << "Eating";
	pMiner->incrHunger(4);
}

void Eating::Exit(Miner* pMiner)
{
	std::cout << "leaving restaurant. \n";
}
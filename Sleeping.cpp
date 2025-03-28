#include "Miner.h"
#include "Sleeping.h"
#include <iostream>


void Sleeping::Enter(Miner* pMiner) 
{
	if (std::strcmp(pMiner->GetLocation().c_str(), "home")) 
	{
		std::cout << (pMiner->GetID()) << ": " << "has arrived home.\n";
		pMiner->ChangeLocation("home");
	}
	
}

void Sleeping::Execute(Miner* pMiner) 
{
	if (pMiner->GetUpgrade(1).bIsBought)
		pMiner->incrFatigue(5);
	else
		pMiner->incrFatigue(3);
}

void Sleeping::Exit(Miner* pMiner)
{
	std::cout << "leaving home.\n";
}

const char* Sleeping::Statename()
{
	const char* Statename = new char;
	Statename = "sleeping";
	return Statename;
}
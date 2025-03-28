#include "Miner.h"
#include "Moving.h"
#include <iostream>


void Moving::Enter(Miner* pMiner) 
{
	if (std::strcmp(pMiner->GetLocation().c_str(), "outside"))
	{
		std::cout << (pMiner->GetID()) << ": " << "is preparing to move\n";
		pMiner->ChangeLocation("outside");
	}
}

void Moving::Execute(Miner* pMiner) 
{
	pMiner->movedelay++;
}

void Moving::Exit(Miner* pMiner)
{
	//std::cout << (pMiner->GetID()) << ": " << "has left " << pMiner->GetLocation() << "\n";
}

const char* Moving::Statename()
{
	const char* Statename = new char;
	Statename = "moving";
	return Statename;
}
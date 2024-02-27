#include "Miner.h"
#include "Moving.h"
#include <iostream>


void Moving::Enter(Miner* pMiner) {
	std::cout << "\n" << (pMiner->GetID()) << ": " << "is preparing to move";
}

void Moving::Execute(Miner* pMiner) {
	movedelay++;
}

void Moving::Exit(Miner* pMiner)
{

}
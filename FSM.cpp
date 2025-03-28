#include "Miner.h"

Miner miner1(1);
Miner miner2(2);
Miner miner3(3);
Miner miner4(4);
std::vector<Miner> miners = { miner1, miner2, miner3, miner4 };
int textspacing = 34;
int timestepinput = 1;

int globaltime = 0;
int main()
{
	
	while (timestepinput != 0) 
	{
		system("cls");
		std::cout << "\n";
		if (globaltime % 24 > 12)
			std::cout << "Global time: " << globaltime % 24 - 12 << " PM\n";
		else if (globaltime % 24 == 0)
			std::cout << "Global time: " << 12 << " PM\n";
		else
			std::cout << "Global time: " << globaltime % 24 << " AM\n";
		std::cout << "Days since birth: " << globaltime / 24 << "\n\n";


		for(int i = 0; i < 7; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if (i == 0)
					std::cout << "Miner ID: " << miners.at(j).GetID() << std::setw(textspacing - AmountOfDigits(miners.at(j).GetID()));
				else if (i == 1)
					std::cout << "Gold: " << miners.at(j).GetGold() << std::setw(textspacing - AmountOfDigits(miners.at(j).GetGold()));
				else if (i == 2)
					std::cout << "Hunger: " << miners.at(j).GetHunger() << std::setw(textspacing - AmountOfDigits(miners.at(j).GetHunger()));
				else if (i == 3)
					std::cout << "Thirst: " << miners.at(j).GetThirst() << std::setw(textspacing - AmountOfDigits(miners.at(j).GetThirst()));
				else if (i == 4)
					std::cout << "Fatigue: " << miners.at(j).GetFatigue() << std::setw(textspacing - AmountOfDigits(miners.at(j).GetFatigue()));
				else if (i == 5)
					std::cout << "Current State: " << miners.at(j).GetStatename() << std::setw(textspacing - strlen(miners.at(j).GetStatename()));
				else if (i == 6)
					std::cout << "Current Location: " << miners.at(j).GetLocation() << std::setw(textspacing - miners.at(j).GetLocation().size());
			}
			std::cout << "\n";
		}
		
		std::cout << "\n";
		for (int i = 0; i < 4; i++)
		{
			miners.at(i).Update(&miners);
			std::cout << "\n";
		}
		

		timestepinput--;
		if (timestepinput == 0) 
		{
			std::cout << "\n\n\nInsert how many timesteps to progress: ";	
			scanf_s("%i", &timestepinput);
		}

		globaltime++;
		//update cycle
		Sleep(5);

	}
}
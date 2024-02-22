
#include "Miner.h"
#include <Windows.h>
#include <stdlib.h>

#include <iostream>


Miner miner(1);
int main()
{
	while (true) {
		system("cls");
		miner.Update();

		//update cycle
		Sleep(50);
	}
}
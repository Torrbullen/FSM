#include "Miner.h"

Miner miner(1);
int main()
{
	while (true) {
		system("cls");
		miner.Update();

		//update cycle
		Sleep(200);
	}
}
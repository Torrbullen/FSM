#pragma once
#include "State.h"
#include <string>
#include <string.h>
#include <cstring>
#include <map>
#include <iostream>



class Miner {

private:
	State* m_pCurrentState;
	std::string m_Location;
	int id;
	int m_GoldCarried;
	int m_Thirst;
	int m_Fatigue;
	int m_Hunger;

public:
	Miner(int ID);
	void Update();

	std::string GetLocation();
	int GetID();
	int GetGold();
	int GetFatigue();
	int GetThirst();
	int GetHunger();
	State* GetState();

	void ChangeState(State* pNewState);
	void ChangeLocation(std::string newLocation);

	void decrGold();
	void decrFatigue();
	void decrThirst();
	void decrHunger();

	void decrGold(int decr);
	void decrFatigue(int decr);
	void decrThirst(int decr);
	void decrHunger(int decr);

	void incrGold();
	void incrFatigue();
	void incrThirst();
	void incrHunger();

	void incrGold(int incr);
	void incrFatigue(int incr);
	void incrThirst(int incr);
	void incrHunger(int incr);

};

//std::map<std::string, int> LocationMap = { {"goldmine", 0}, {"bar", 1}, {"restaurant", 2}, {"home", 3},{"store", 4},{"office", 5} };

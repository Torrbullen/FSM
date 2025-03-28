#pragma once
#include "State.h"
#include <string>
#include <string.h>
#include <cstring>
#include <sstream>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <assert.h>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <vector>



struct ShopUpgrade
{
	bool bIsBought;
	int price;
};
struct Message 
{ 
	int messagetype;	//0 = invite, 1 = acceptedresponse, 2 = declinedresponse  
	int senderID;
	std::string contains; 

	Message(int msgtype, int senderid, std::string msgbody) { messagetype = msgtype; senderID = senderid; contains = msgbody; }
};
class Miner 
{

private:
	State* m_pCurrentState;
	State* m_pLastState;
	std::string m_Location;
	std::string m_pLastEmergentState;
	int id;
	int m_GoldCarried;
	int m_Thirst;
	int m_Fatigue;
	int m_Hunger;
	int cooldown;
	int timesincebirth;
	int incrsincebirth;
	int daysincebirth;
	int hangoutcooldown;
	ShopUpgrade bIsCertifiedShoveler;
	ShopUpgrade bIsRoyal;
	ShopUpgrade bIsNectarEnjoyer;
	ShopUpgrade bIsAmbrosiaEnjoyer;
	ShopUpgrade bIsChainsawing;
	ShopUpgrade Upgrades[5];
	std::vector<Message> pendingmsglist;

public:
	Miner(int ID);
	void Update(std::vector<Miner> *listofminers);
	int movedelay;

	std::string GetLocation();
	int GetID();
	int GetGold();
	int GetFatigue();
	int GetThirst();
	int GetHunger();
	State* GetState();
	const char* GetStatename();
	std::vector<Message>* GetMessageList();

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

	void PurchaseCertificate(int orderedupgrade);
	ShopUpgrade GetUpgrade(int orderedupgrade);

};

//std::map<std::string, int> LocationMap = { {"goldmine", 0}, {"bar", 1}, {"restaurant", 2}, {"home", 3},{"store", 4},{"office", 5} };

int AmountOfDigits(int number);
#include "Miner.h"
#include "Mining.h"
#include "Drinking.h"
#include "Eating.h"
#include "Sleeping.h"
#include "Moving.h"
#include "Shopping.h"
#include "Lumbering.h"

Miner::Miner(int ID) 
{
	m_pCurrentState = &Mining::Instance();
	m_pLastState = &Mining::Instance();
	id = ID;
	m_GoldCarried = 0;
	m_Fatigue = rand() % 50 + 50;
	m_Thirst = rand() % 50 + 50;
	m_Hunger = rand() % 50 + 50;
	cooldown = 4;
	timesincebirth = 0;
	incrsincebirth = 0;
	daysincebirth = 0;
	hangoutcooldown = 0;
	movedelay = 0;
	bIsCertifiedShoveler.bIsBought = false;
	bIsCertifiedShoveler.price = 100;
	bIsRoyal.bIsBought = false;
	bIsRoyal.price = 500;
	bIsNectarEnjoyer.bIsBought = false;
	bIsNectarEnjoyer.price = 1000;
	bIsAmbrosiaEnjoyer.bIsBought = false;
	bIsAmbrosiaEnjoyer.price = 2000;
	bIsChainsawing.bIsBought = false;
	bIsChainsawing.price = 100;
	Upgrades[0] = bIsCertifiedShoveler;
	Upgrades[1] = bIsRoyal;
	Upgrades[2] = bIsNectarEnjoyer;
	Upgrades[3] = bIsAmbrosiaEnjoyer;
	Upgrades[4] = bIsChainsawing;
	m_Location = "goldmine";
	m_pLastEmergentState = "chillin";
}

void Miner::ChangeState(State* pNewState) 
{
	assert(m_pCurrentState && pNewState);
	//IMPLEMENT LAST STATE
	m_pCurrentState->Exit(this);
	m_pCurrentState = pNewState;
	m_pCurrentState->Enter(this);
}
void Miner::ChangeLocation(std::string newLocation) 
{
	m_Location = newLocation;
}

std::string Miner::GetLocation() 
{
	return this->m_Location;
}

int Miner::GetID() 
{
	return this->id;
}

int Miner::GetHunger() 
{
	return this->m_Hunger;
}

ShopUpgrade Miner::GetUpgrade(int orderedupgrade)
{
	return Upgrades[orderedupgrade];
}

int Miner::GetGold() 
{
	return this->m_GoldCarried;
}

int Miner::GetThirst() 
{
	return this->m_Thirst;
}

int Miner::GetFatigue() 
{
	return this->m_Fatigue;
}

State* Miner::GetState() 
{
	return this->m_pCurrentState;
}

const char* Miner::GetStatename()
{
	return this->m_pCurrentState->Statename();
}

std::vector<Message>* Miner::GetMessageList()
{
	return &this->pendingmsglist;
}

void Miner::decrFatigue() 
{
	m_Fatigue--;

	if (m_Fatigue < 0) 
	{
		m_Fatigue = 0;
	}
}
void Miner::decrFatigue(int decr) 
{
	m_Fatigue -= decr;

	if (m_Fatigue < 0) 
	{
		m_Fatigue = 0;
	}
}

void Miner::decrHunger() 
{
	m_Hunger--;

	if (m_Hunger < 0) 
	{
		m_Hunger = 0;
	}
}
void Miner::decrHunger(int decr) 
{
	m_Hunger -= decr;

	if (m_Hunger < 0) 
	{
		m_Hunger = 0;
	}
}

void Miner::decrThirst() 
{
	m_Thirst--;

	if (m_Thirst < 0) 
	{
		m_Thirst = 0;
	}
}
void Miner::decrThirst(int decr) 
{
	m_Thirst -= decr;

	if (m_Thirst < 0)
	{
		m_Thirst = 0;
	}
}

void Miner::decrGold()
{
	m_GoldCarried--;

	if (m_GoldCarried < 0)
	{
		m_GoldCarried = 0;
	}
}
void Miner::decrGold(int decr) 
{
	m_GoldCarried -= decr;

	if (m_GoldCarried < 0) 
	{
		m_GoldCarried = 0;
	}
}


void Miner::incrFatigue() 
{
	m_Fatigue++;

	if (m_Fatigue > 100)
	{
		m_Fatigue = 100;
	}
}
void Miner::incrFatigue(int incr) 
{
	m_Fatigue += incr;

	if (m_Fatigue > 100) 
	{
		m_Fatigue = 100;
	}
}

void Miner::incrHunger() 
{
	m_Hunger++;

	if (m_Hunger > 100) 
	{
		m_Hunger = 100;
	}
}
void Miner::incrHunger(int incr)
{
	m_Hunger += incr;

	if (m_Hunger > 100) 
	{
		m_Hunger = 100;
	}
}

void Miner::incrThirst() 
{
	m_Thirst++;

	if (m_Thirst > 100) 
	{
		m_Thirst = 100;
	}
}
void Miner::incrThirst(int incr) 
{
	m_Thirst += incr;

	if (m_Thirst > 100) 
	{
		m_Thirst = 100;
	}
}

void Miner::incrGold() 
{
	m_GoldCarried++;
}
void Miner::incrGold(int incr) 
{
	m_GoldCarried += incr;
}

void Miner::PurchaseCertificate(int orderedupgrade)
{
	this->decrGold(Upgrades[orderedupgrade].price);
	Upgrades[orderedupgrade].bIsBought = true;
	if (orderedupgrade == 0)
		std::cout << "shovel certificate purchased";
	else if (orderedupgrade == 1)
		std::cout << "royal bed purchased";
	else if (orderedupgrade == 2)
		std::cout << "nectar purchased";
	else if (orderedupgrade == 3)
		std::cout << "ambrosia purchased";
	else if (orderedupgrade == 4)
		std::cout << "chainsaw purchased";
}

Miner GetMinerByID(std::vector<Miner> listofminers, int ID)
{
	int minernum = 0;
	for (Miner miner : listofminers)
	{
		if (miner.GetID() == ID)
			break;
		minernum++;
	}
	return listofminers.at(minernum);
}

//Goes into main function.
void Miner::Update(std::vector<Miner> *listofminers)
{
	bool bCanPurchase;
	
	if (incrsincebirth % 2 == 0)
	{
		this->decrFatigue();
		this->decrHunger();
		this->decrThirst();
	}

	this->GetState()->Execute(this);

	int EmergentStat = (std::min)((std::min)((std::min)(m_Thirst, m_Hunger), m_Fatigue), 70);
	std::string EmergentState[1];

	if(!m_pLastEmergentState.substr(0, m_pLastEmergentState.find(" ")).compare("hangoutmaxxing") && hangoutcooldown < 8)
	{
		EmergentState->assign(m_pLastEmergentState);
		hangoutcooldown++;
	}
	else {
		if (EmergentStat == m_Thirst)
		{
			EmergentState->assign("thirsty");
		}
		else if (EmergentStat == m_Hunger)
		{
			EmergentState->assign("hungry");
		}
		else if (EmergentStat == m_Fatigue)
		{
			EmergentState->assign("tired");
		}
		else
		{
			EmergentState->assign("chillin");
		}
	}
	
	//check pending messages
	for (int i = 0; i < this->GetMessageList()->size(); i++)
	{
		std::cout << this->GetID() << " has received a message from " << this->GetMessageList()->at(i).senderID << " containing: " << this->GetMessageList()->at(i).contains << std::endl;
		if (this->GetMessageList()->at(i).messagetype == 0 && EmergentState->compare("chillin"))
		{
			GetMinerByID(*listofminers, this->GetMessageList()->at(i).senderID).GetMessageList()->push_back(Message(2, this->GetID(), "turned down invitation"));
			std::cout << this->GetID() << " has turned down the invitation\n";
		}
		else if (this->GetMessageList()->at(i).messagetype == 0 && !EmergentState->compare("chillin"))
		{
			GetMinerByID(*listofminers, this->GetMessageList()->at(i).senderID).GetMessageList()->push_back(Message(1, this->GetID(), "accepted invitation"));
			std::cout << this->GetID() << " has accepted the invitation\n";
			
			auto pos = this->GetMessageList()->at(i).contains.find(" ");
			std::string activitytodo = this->GetMessageList()->at(i).contains.substr(0, pos);

			if (!activitytodo.compare("Dinner"))
			{
				EmergentState->assign("hangoutmaxxing Dinner");
			}
			else if (!activitytodo.compare("Drinking"))
			{
				EmergentState->assign("hangoutmaxxing Drinking");
			}
			else if (!activitytodo.compare("Shopping"))
			{
				EmergentState->assign("hangoutmaxxing Shopping");
			}
			else if (!activitytodo.compare("Sleepover"))
			{
				EmergentState->assign("hangoutmaxxing Sleepover");
			}
			hangoutcooldown = 0;
		}
	}
	pendingmsglist.clear();

	//which is cheapest upgrade
	for (int i = 0; i < 4; i++)
	{
		if (Upgrades[i].bIsBought == false)
		{
			if (m_GoldCarried >= Upgrades[i].price)
			{
				bCanPurchase = true;
				break;
			}
		}
		bCanPurchase = false;
	}

	if ((!EmergentState->compare("thirsty") || !EmergentState->compare("hangoutmaxxing Drinking")) && m_pCurrentState != &Drinking::Instance())
	{
		if (m_pCurrentState != &Moving::Instance() && cooldown > 3)
		{
			ChangeState(&Moving::Instance());
		}
		if (movedelay > 1) 
		{
			ChangeState(&Drinking::Instance());
			movedelay = 0;
			cooldown = 0;
		}
	}
	else if ((!EmergentState->compare("hungry") || !EmergentState->compare("hangoutmaxxing Dinner")) && m_pCurrentState != &Eating::Instance() )
	{
		if (m_pCurrentState != &Moving::Instance() && cooldown > 3)
		{
			ChangeState(&Moving::Instance());
		}
		if (movedelay > 1) 
		{
			ChangeState(&Eating::Instance());
			movedelay = 0;
			cooldown = 0;
		}
	}
	else if ((!EmergentState->compare("tired") || !EmergentState->compare("hangoutmaxxing Sleepover")) && m_pCurrentState != &Sleeping::Instance() )
	{
		if (m_pCurrentState != &Moving::Instance() && cooldown > 3) 
		{
			ChangeState(&Moving::Instance());
		}
		if (movedelay > 1) 
		{
			ChangeState(&Sleeping::Instance());
			movedelay = 0;
			cooldown = 0;
		}
	}
	else if (((bCanPurchase && !EmergentState->compare("chillin")) || !EmergentState->compare("hangoutmaxxing Shopping")) && m_pCurrentState != &Shopping::Instance() )
	{
		if (m_pCurrentState != &Moving::Instance() && cooldown > 3) {
			ChangeState(&Moving::Instance());
		}
		if (movedelay > 2) {
			ChangeState(&Shopping::Instance());
			movedelay = 0;
			cooldown = 0;
		}
	}
	else if (!bCanPurchase && !EmergentState->compare("chillin") && m_pCurrentState != &Mining::Instance())
	{
		std::srand(incrsincebirth);
		int decision = std::rand() % 70;
		if (decision <= 7)
		{
			std::string activity;
			if (decision < 2)
			{
				activity = "Dinner invitation";
			}
			else if (1 < decision && decision < 4)
			{
				activity = "Drinking invitation";
			}
			else if (3 < decision && decision < 6)
			{
				activity = "Shopping invitation";
			}
			else
			{
				activity = "Sleepover invitation";
			}

			for (int i = 0; i < listofminers->size(); i++)
			{
				if (listofminers->at(i).GetID() != this->GetID())
				{
					listofminers->at(i).GetMessageList()->push_back(Message(0, this->GetID(), activity));
				}
				else
				{
					EmergentState->assign("hangoutmaxxing " + activity.substr(0, activity.find(" ")));
					hangoutcooldown = 0;
				}
			}
		}
		else if (decision > 50)
		{
			if (m_pCurrentState != &Moving::Instance() && cooldown > 3) {
				ChangeState(&Moving::Instance());
			}
			if (movedelay > 2) {
				ChangeState(&Lumbering::Instance());
				movedelay = 0;
				cooldown = 0;
			}
		}
		else
		{
			if (m_pCurrentState != &Moving::Instance() && cooldown > 3) {
				ChangeState(&Moving::Instance());
			}
			if (movedelay > 2) {
				ChangeState(&Mining::Instance());
				movedelay = 0;
				cooldown = 0;
			}
		}
	}

	cooldown++;
	incrsincebirth++;
	m_pLastEmergentState.clear();
	m_pLastEmergentState.append(*EmergentState);
}


int AmountOfDigits(int number)
{
	int AmountOfDigits = 0;
	while (number != 0)
	{
		number = number / 10;
		AmountOfDigits++;
	}

	return AmountOfDigits;
}


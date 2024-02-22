#include "Miner.h"
#include "Mining.h"
#include "Bar.h"
#include "State.h"
#include <assert.h>

Miner::Miner(int ID) {
	m_pCurrentState = &Mining::Instance();
	id = ID;
	m_GoldCarried = 0;
	m_Fatigue = 100;
	m_Thirst = 100;
	m_Hunger = 100;
}

void Miner::ChangeState(State* pNewState) {
	assert(m_pCurrentState && pNewState);
	m_pCurrentState->Exit(this);
	m_pCurrentState = pNewState;
	m_pCurrentState->Enter(this);
}
void Miner::ChangeLocation(std::string newLocation) {
	m_Location = newLocation;
}

std::string Miner::GetLocation() {
	return this->m_Location;
}

int Miner::GetID() {
	return this->id;
}

int Miner::GetHunger() {
	return this->m_Hunger;
}

int Miner::GetGold() {
	return this->m_GoldCarried;
}

int Miner::GetThirst() {
	return this->m_Thirst;
}

int Miner::GetFatigue() {
	return this->m_Fatigue;
}

State* Miner::GetState() {
	return this->m_pCurrentState;
}

void Miner::decrFatigue() {
	m_Fatigue--;
	if (m_Fatigue < 0) {
		m_Fatigue = 0;
	}
}
void Miner::decrFatigue(int decr) {
	m_Fatigue -= decr;
	if (m_Fatigue < 0) {
		m_Fatigue = 0;
	}
}

void Miner::decrHunger() {
	m_Hunger--;
	if (m_Hunger < 0) {
		m_Hunger = 0;
	}
}
void Miner::decrHunger(int decr) {
	m_Hunger -= decr;
	if (m_Hunger < 0) {
		m_Hunger = 0;
	}
}

void Miner::decrThirst() {
	m_Thirst--;
	if (m_Thirst < 0) {
		m_Thirst = 0;
	}
}
void Miner::decrThirst(int decr) {
	m_Thirst -= decr;
	if (m_Thirst < 0) {
		m_Thirst = 0;
	}
}

void Miner::decrGold() {
	m_GoldCarried--;
	if (m_GoldCarried < 0) {
		m_GoldCarried = 0;
	}
}
void Miner::decrGold(int decr) {
	m_GoldCarried -= decr;
	if (m_GoldCarried < 0) {
		m_GoldCarried = 0;
	}
}


void Miner::incrFatigue() {
	m_Fatigue++;
	if (m_Fatigue > 100) {
		m_Fatigue = 100;
	}
}
void Miner::incrFatigue(int incr) {
	m_Fatigue += incr;
	if (m_Fatigue > 100) {
		m_Fatigue = 100;
	}
}

void Miner::incrHunger() {
	m_Hunger++;
	if (m_Hunger > 100) {
		m_Hunger = 100;
	}
}
void Miner::incrHunger(int incr) {
	m_Hunger += incr;
	if (m_Hunger > 100) {
		m_Hunger = 100;
	}
}

void Miner::incrThirst() {
	m_Thirst++;
	if (m_Thirst > 100) {
		m_Thirst = 100;
	}
}
void Miner::incrThirst(int incr) {
	m_Thirst += incr;
	if (m_Thirst > 100) {
		m_Thirst = 100;
	}
}

void Miner::incrGold() {
	m_GoldCarried++;
}
void Miner::incrGold(int incr) {
	m_GoldCarried += incr;
}

//Goes into main function.
void Miner::Update() {
	this->decrFatigue();
	this->decrHunger();
	this->decrThirst();
	std::cout << "Miner:	" << this->id << "\n";
	std::cout << "current state:	";
	this->GetState()->Execute(this);
	std::cout << "\n\n";
	std::cout << "gold: " << this->GetGold() << "\n"
		<< "hunger: " << this->GetHunger() << "\n"
		<< "thirst: " << this->GetThirst() << "\n"
		<< "fatigue: " << this->GetFatigue() << "\n";
	if (m_Thirst < 50 && m_pCurrentState != &Bar::Instance()) {
		ChangeState(&Bar::Instance());
	}
}
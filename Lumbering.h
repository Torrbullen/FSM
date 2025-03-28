#pragma once
#include "State.h"

class Lumbering : public State
{
public:
	static Lumbering& Instance()
	{
		static Lumbering instance;
		return instance;
	};
private:
	Lumbering() {}

public:
	virtual void Enter(Miner* pMiner);
	virtual void Execute(Miner* pMiner);
	virtual void Exit(Miner* pMiner);
	virtual const char* Statename();

	Lumbering(Lumbering const&) = delete;
	void operator=(Lumbering const&) = delete;
};
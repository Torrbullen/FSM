#pragma once
#include "State.h"

class Sleeping : public State 
{
public:
	static Sleeping& Instance()
	{
		static Sleeping instance;
		return instance;
	};
private:
	Sleeping() {}

public:
	virtual void Enter(Miner* pMiner);
	virtual void Execute(Miner* pMiner);
	virtual void Exit(Miner* pMiner);
	virtual const char* Statename();

	Sleeping(Sleeping const&) = delete;
	void operator=(Sleeping const&) = delete;
};

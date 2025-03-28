#pragma once
#include "State.h"

class Moving : public State 
{
public:
	static Moving& Instance()
	{
		static Moving instance;
		return instance;
	};
private:
	Moving() {}

public:
	virtual void Enter(Miner* pMiner);
	virtual void Execute(Miner* pMiner);
	virtual void Exit(Miner* pMiner);
	virtual const char* Statename();

	Moving(Moving const&) = delete;
	void operator=(Moving const&) = delete;
};

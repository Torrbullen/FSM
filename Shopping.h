#pragma once
#include "State.h"

class Shopping : public State
{
public:
	static Shopping& Instance()
	{
		static Shopping instance;
		return instance;
	};
private:
	Shopping() {}

public:
	virtual void Enter(Miner* pMiner);
	virtual void Execute(Miner* pMiner);
	virtual void Exit(Miner* pMiner);
	virtual const char* Statename();

	Shopping(Shopping const&) = delete;
	void operator=(Shopping const&) = delete;
};
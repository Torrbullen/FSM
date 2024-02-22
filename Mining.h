#pragma once
#include "State.h"

class Mining : public State {
public:
	static Mining& Instance()
	{
		static Mining instance;
		return instance;
	};
private:
	Mining() {}

public:
	virtual void Enter(Miner* pMiner);
	virtual void Execute(Miner* pMiner);
	virtual void Exit(Miner* pMiner);

	Mining(Mining const&) = delete;
	void operator=(Mining const&) = delete;
};

#pragma once
#include "State.h"

class Eating : public State {
public:
	static Eating& Instance()
	{
		static Eating instance;
		return instance;
	};
private:
	Eating() {}

public:
	virtual void Enter(Miner* pMiner);
	virtual void Execute(Miner* pMiner);
	virtual void Exit(Miner* pMiner);

	Eating(Eating const&) = delete;
	void operator=(Eating const&) = delete;
};

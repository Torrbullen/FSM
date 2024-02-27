#pragma once
#include "State.h"

class Drinking : public State {
public:
	static Drinking& Instance()
	{
		static Drinking instance;
		return instance;
	};
private:
	Drinking() {}

public:
	virtual void Enter(Miner* pMiner);
	virtual void Execute(Miner* pMiner);
	virtual void Exit(Miner* pMiner);

	Drinking(Drinking const&) = delete;
	void operator=(Drinking const&) = delete;
};

#pragma once
#include "State.h"

class Bar : public State {
public:
	static Bar& Instance()
	{
		static Bar instance;
		return instance;
	};
private:
	Bar() {}

public:
	virtual void Enter(Miner* pMiner);
	virtual void Execute(Miner* pMiner);
	virtual void Exit(Miner* pMiner);

	Bar(Bar const&) = delete;
	void operator=(Bar const&) = delete;
};

#pragma once

const int timestepspeed = 5;

class Miner;
class State 
{
public:
	virtual ~State() {}
	virtual void Enter(Miner*) = 0;
	virtual void Execute(Miner*) = 0;
	virtual void Exit(Miner*) = 0;
	virtual const char* Statename() = 0;

};

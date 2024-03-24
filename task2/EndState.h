#pragma once
#include "Machine.h"
#include "takingMoneyState.h"
class EndState :
	public State
{
public:
	EndState(std::stack<State*>* states)
	{
		this->states = states;
	}
	
private:
	void runState()
	{
		printGoodbye();
		quitWholeMachine();
	}
	void printGoodbye() const
	{
		std::cout << "Dziekujemy za skorzystanie z biletomatu Krakowskiej Komunikacji Miejskiej!\n";
		std::cout << "Zyczymy udanej podrozy i milego dnia. Do zobaczenia nastepnym razem!\n\n\n";

		std::chrono::duration<int, std::milli> timespan(3000);
		std::this_thread::sleep_for(timespan);
	}
};
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <chrono>
#include <thread>
#include <type_traits>
#include <typeinfo>
#include "State.h"
#include "takingMoneyState.h"
class Machine
{
private:
	std::stack <State*> states;
public:
	Machine()
	{
		this->states.push(new takingMoneyState(&this->states));
		showInfo();
	}
	~Machine()
	{
		
	}
	void restartMachine()
	{
		while (states.size() != 0)
		{
			auto ptr = states.top();
			states.pop();
			delete ptr;
		}
		this->states.push(new takingMoneyState(&this->states));
		runMachine();
	}
	void showInfo() const
	{
		std::cout << "BILETOMAT KRAKOWSKIEGO TRANSPORTU PUBLICZNEGO!\n";
		std::cout << "KROTKA INSTRUKCJA!\n";
		std::cout << "Aby cofnac sie o jeden stan wpisz -1!\n";
		std::cout << "Aby cofnac sie do pierwszego stanu wpisz -2!\n\n";
	}
	void runMachine()
	{
		while (states.size() != 0)
		{
			if (states.top()->getQuitMachine())
				restartMachine();
			if (!states.top()->getQuit())
				states.top()->runState();
			else
			{
				delete states.top();
				states.pop();
			}
		}
		restartMachine();
	}
};
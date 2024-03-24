#pragma once
#include "choosingTicketState.h"
class takingMoneyState : 
	public State 
{
private:
	int coinSum = 0;
public:
	takingMoneyState(std::stack<State*> *states)
	{
		this->states = states;
	}
private:
	void runState()
	{
		showSalesInfo();
		handleInput();
	}
	void showSalesInfo() const
	{
		std::cout << "Wrzuc po kolei monety, jezeli juz wystarczy wpisz -3\n";
	}
	void handleInput()
	{
		auto tempCoin{ 0 };
		while (true)
		{
			std::cout << "SALDO:" << coinSum << std::endl;
			if (!(std::cin >> tempCoin))
			{
				std::cout << "Podaj poprawna wartosc\n";
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				continue;
			}
			if (tempCoin == -1 || tempCoin == -2)
			{
				quitState();
				return;
			}
			if (tempCoin == -3)
				break;
			if (tempCoin > 0)
				coinSum += tempCoin;
		}
		this->states->push(new ChoosingTicketState(this->states, coinSum));
	}
};
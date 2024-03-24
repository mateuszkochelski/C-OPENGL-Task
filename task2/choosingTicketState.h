#pragma once
#include "Machine.h"
#include "PrintTIcketState.h"
class ChoosingTicketState :
	public State
{
private:
	const int moneyInMachine;
	const std::unordered_set<int> ticketCosts{ 3,4,8,10,15 };
public:
	ChoosingTicketState(std::stack<State*>* states, int money)
		: moneyInMachine{ money } {
		this->states = states;
	}
	void runState()
	{
		askForTicket();
		selectTicket();
	}
	void askForTicket() const
	{
		std::cout << "Dostepne ceny biletow to: 3, 4, 8, 10, 15\n Wybierz za ile chcesz kupic\n";
	}
	void selectTicket()
	{
		int choosenCost = 0;
		std::cin >> choosenCost;
		if (choosenCost == -1)
		{
			quitState();
			return;
		}
		if (choosenCost == -2)
		{
			quitWholeMachine();
			return;
		}
		if (ticketCosts.contains(choosenCost) && moneyInMachine >= choosenCost)
		{
			this->states->push(new PrintTicketState(states, moneyInMachine, choosenCost));
		}
		else
		{
			std::cout << "Wybierz poprawna cene biletu lub wybierz -1 aby ponownie wrzucic monety\n";
			selectTicket();
		}
	}

};

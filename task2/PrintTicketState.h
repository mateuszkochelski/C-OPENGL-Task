#pragma once
#include "choosingTicketState.h"
#include "RefundMoneyState.h"
#include "Machine.h"

#include <fstream>
class PrintTicketState :
	public State
{
private:
	const int moneyInMachine;
	const int ticketCost;
	std::string fullName;
	std::unordered_map<std::string, std::vector<std::string>> ticketsImages;
public:
	PrintTicketState(std::stack<State*>* states, int moneyInMachine, int ticketCost)
		:moneyInMachine{ moneyInMachine }, ticketCost{ ticketCost }
	{
		this->states = states;
	}
private:
	void runState()
	{
		initTickets();
		printTicket(ticketCost);
		inputData();
	}
	void initTickets()
	{
		std::ifstream tickets("tickets.ini");

		if (tickets.is_open())
		{
			std::string key;
			std::string line;

			while (std::getline(tickets, key))
			{
				while (std::getline(tickets, line))
				{
					ticketsImages[key].push_back(line);
					if (line[line.length() - 1] == '*')
						break;
				}
			}
		}
		tickets.close();
	}
	void printTicket(const int ticketCost) const
	{
		for (const auto& s : ticketsImages.at(std::to_string(ticketCost)))
		{
			std::cout << s << std::endl;
			std::chrono::duration<int, std::milli> timespan{ 100 };
			std::this_thread::sleep_for(timespan);
		}
		std::cout << "Wlasciciel biletu:" << fullName << std::endl;

	}
	void inputData() {
		std::cout << "Podaj imie i nazwisko\n";
		std::cin >> fullName;
		if (fullName == "-1")
		{
			quitState();
			return;
		}
		if (fullName == "-2")
		{
			quitWholeMachine();
			return;
		}
		this->states->push(new RefundMoneyState(states, moneyInMachine, ticketCost));
	}
};
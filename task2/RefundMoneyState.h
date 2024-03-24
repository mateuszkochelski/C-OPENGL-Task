#include "Machine.h"
#include "EndState.h"
class RefundMoneyState :
	public State
{
private:
	std::vector<int> Rest_in_coins_5_2_1 = { 0,0,0 };
	int moneyInMachine;
	int ticketCost;
public:
	RefundMoneyState(std::stack<State*>* states, int moneyInMachine, int ticketCost):
		moneyInMachine(moneyInMachine), ticketCost(ticketCost)
	{
		this->states = states;
	}
private:
	void runState()
	{
		calculateRest();
		printRest();
		this->states->push(new EndState(states));
	}
	void calculateRest()
	{
		int Rest = moneyInMachine - ticketCost;
		Rest_in_coins_5_2_1[0] = Rest / 5;
		Rest_in_coins_5_2_1[1] = (Rest % 5) / 2;
		Rest_in_coins_5_2_1[2] = (Rest % 5) % 2;
	}
	void printRest() const
	{
		std::cout << "Oto twoja reszta!\n";
		std::cout << Rest_in_coins_5_2_1[0] << " 5-zlotowek\n";
		std::cout << Rest_in_coins_5_2_1[1] << " 2-zlotowek\n";
		std::cout << Rest_in_coins_5_2_1[2] << " 1-zlotowek\n";
	}
	
};
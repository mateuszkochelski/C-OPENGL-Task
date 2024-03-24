#pragma once
#include <stack>

class State
{
private:
	bool quit{ false };
	bool quitMachine{ false };
protected:
	std::stack <State*>* states;
public:
	virtual void runState() = 0;
	bool getQuit() const {
		return quit;
	}
	bool getQuitMachine() const {
		return quitMachine;
	}
protected:
	void quitState() {
		quit = true;
	}
	void quitWholeMachine()
	{
		quitMachine = true;
	}
};

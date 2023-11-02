#ifndef MACHINE_H
#define MACHINE_H
#include <unordered_map>
#include <vector>

struct State {
    std::string name;
    bool isStart;
    bool isAccept;
    State(std::string name, bool isStart, bool isAccept) {
        this->name = name;
        this->isStart = isStart;
        this->isAccept = isAccept;
    }
};

struct Transition {
    State *from;
    State *to;
    std::string *symbol;
};

class DFA {
private:
    int numStates;
    std::unordered_map<int, State> states;
    std::vector<std::string> symbols;
    std::unordered_map<std::string, Transition> transitions;
public:
    void addState(State state, bool isStart, bool isAccept);

    State getState();

    void addSymbol();

    std::string getSymbol();

    void addTransition();

    Transition getTransition();
};

class NFA {

};

class PDA {

};

#endif MACHINEFUNCTIONS_H



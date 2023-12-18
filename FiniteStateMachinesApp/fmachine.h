/*
 * All DFAs are NFAs, so we only need to define an NFA class
 * In previous versions there was a Graph structure defined,
 * but that is no longer necessary. All functionality that the
 * graph class has can be done with only the Transition class.
*/

#ifndef FMACHINE_H
#define FMACHINE_H
#include <set>
#include <unordered_map>
#include <vector>
#include <utility>

class NFA {
private:
    std::set<int> states;
    std::set<char> symbols;
    std::unordered_map<int, std::vector<std::pair<char, int> > > transitions;
    int startState;
    std::set<int> acceptStates;
public:
    NFA() {
        startState = -1;
    }
    void addState(int state, bool isStart, bool isAccept);

    std::set<int> getStates() { return states; }

    std::set<int> getAcceptStates() { return acceptStates; }

    void addSymbol(char symbol);

    void addTransition(int from, char on, int to);

    std::vector<std::pair<char, int> > getTransitions(int state) { return transitions[state]; }

    std::unordered_map<int, std::vector<std::pair<char, int> > > getTransitions() { return transitions; }

    bool accepts(std::string input);

    //void setStartState(int state) { startState = state; }
};


#endif // FMACHINE_H
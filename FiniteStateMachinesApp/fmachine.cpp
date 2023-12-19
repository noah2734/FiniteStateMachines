#include "fmachine.h"

#include <set>
#include <unordered_map>
#include <vector>
#include <utility>
#include <string>
#include <iostream>

void NFA::addState(int state, bool isStart, bool isAccept) {
    if (isStart) {
        startState = state;
    }
    if (isAccept) {
        acceptStates.insert(state);
    }
    states.insert(state);
}

void NFA::addSymbol(char symbol) {
    symbols.insert(symbol);
}

void NFA::addTransition(int from, char on, int to) {
    std::pair<char, int> transition;
    transition.first = on;
    transition.second = to;
    transitions[from].push_back(transition);
}

//does not account for epsilon transitions yet
bool NFA::accepts(std::string input) {
    std::set<int> currentStates;
    currentStates.insert(startState);
    for (int i = 0; i < input.length(); i++) {
        std::set<int> nextStates;
        for (int state : currentStates) {
            for (std::pair<char, int> transition : transitions[state]) {
                if (static_cast<int>(transition.first) == -50) {
                    nextStates.insert(transition.second);
                }
                else if (transition.first == input[i]) {
                    nextStates.insert(transition.second);
                }
            }
        }
        currentStates = nextStates;
    }
    for (int state : currentStates) {
        if (acceptStates.find(state) != acceptStates.end()) {
            return true;
        }
    }
    return false;
}
#include "machine.h"

#include <unordered_maps>
#include <vectors>

DFA::addState(State state, bool isStart, bool isAccept) {
    State st(state, isStart, isAccept);
    states[++numStates] = st;

}

#include "machine.h"

#include <unordered_map>
#include <vector>

void DFA::addState(std::string name, bool isStart, bool isAccept) {
    states[name] = State(name, isStart, isAccept);
    numStates++;
}

void DFA::addSymbol(std::string sym) {
    symbols.push_back(sym);
    numSymbols++;
}

std::string DFA::getSymbol(int index) {
    return symbols[index];
}

State DFA::getState(std::string name) {
    return states[name];
}

bool DFA::stateExists(std::string name) {
    auto it = states.find(name);
    if (it != states.end()) {
        return true;
    } else {
        return false;
    }
}

void DFA::addTransition(std::string from, std::string on, std::string to) {
    std::pair<std::string, std::string> key;
    key.first = from;
    key.second = on;
    transitions[key] = Transition(from, on, to);
}

Transition DFA::getTransition(std::pair<std::string, std::string> key) {
    return transitions[key];
}

void Graph::addVertex(Vertex v) {
    if (adj.find(v) == adj.end()) {
        adj[v] = {};
    }
}

void Graph::removeVertex(Vertex v) {
    adj.erase(v);

    //remove edges
    for (auto& pair : adj) {
        pair.second.remove_if([v](const Edge& edge) { return edge.first == v; });
    }
}

bool Graph::isEmpty() const {
    return adj.empty();
}
void Graph::addEdge(Vertex v, Vertex w, Label label) {
    addVertex(v);
    addVertex(w);
    adj[v].push_back({w, label});
}

std::list<Graph::Edge> Graph::getEdges(Vertex v) {
    return adj[v];
}

/**
 * Determines whether the given input string is accepted by the DFA.
 * @param input The input string to be checked.
 * @return True if the input string is accepted, false otherwise.
 */
bool DFA::accepts(std::string input) {
    std::string currentState = startStateName;
    std::pair<std::string, std::string> key;

    for (int i = 0; i < input.size(); i++) {
        key.first = currentState;
        key.second = input[i];

        auto it = transitions.find(key);
        if (it != transitions.end()) {
            currentState = it->second.to;
        } else {
            return false;
        }
    }
    if (states[currentState].isAccept) {
        return true;
    }
    return false;
}

std::string Graph::toString() {
    std::string result = "";
    for (auto& pair : adj) {
        std::string vertex1 = pair.first;
        for (auto& edge : pair.second) {
            result += "      " + edge.second + "\n";
            result += vertex1 + "----->" + edge.first + "\n";
        }
    }
    return result;
}

void NFA::addState(const std::string& name, bool isStart, bool isAccept) {
    states[name] = State(name, isStart, isAccept);
    numStates++;
}

State NFA::getState(const std::string name) {
    return states[name];
}

void NFA::addSymbol(const std::string& sym) {
    symbols.push_back(sym);
    numSymbols++;
}

//First check if transition exists, then only add to transitions if it doesnt already exist
//Key is pair: <From state, Label> and value associated is "To state"
void NFA::addTransition(const std::string& from, const std::string& on, const std::string& to) {
    std::pair<std::string, std::pair<std::string, int>> key;
    std::pair<std::string, int> onValue;
    onValue.first = on;
    onValue.second = 0;
    key.first = from;
    key.second = onValue;
    auto it = transitions.find(key);
    if (it != transitions.end()) {
        if (it->second == to) {
            return;
        } else {
            key.second.second++;
        }
    }
    transitions[key] = Transition(from, on, to);
}

bool NFA::accepts(std::string input) {
    std::string currentState = startStateName;
}



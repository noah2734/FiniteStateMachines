#include "machine.h"

#include <unordered_map>
#include <vector>

void DFA::addState(std::string name, bool isStart, bool isAccept) {
    states[name] = State(name, isStart, isAccept);
}

void DFA::addSymbol(std::string sym) {
    symbols.push_back(sym);
}

State DFA::getState(std::string name) {
    return states[name];
}

void DFA::addTransition(std::string from, std::string on, std::string to) {
    std::pair<std::string, std::string> key;
    key.first = from;
    key.second = to;
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

void Graph::addEdge(Vertex v, Vertex w, Label label) {
    addVertex(v);
    addVertex(w);
    adj[v].push_back({w, label});
}

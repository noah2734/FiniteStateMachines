#ifndef MACHINE_H
#define MACHINE_H
#include <unordered_map>
#include <list>
#include <vector>
#include <string>
#include <utility>

class Graph {
private:
    using Vertex = std::string;
    using Label = std::string;
    using Edge = std::pair<Vertex, Label>;

    std::unordered_map<Vertex, std::list<Edge>> adj;
public:
    void addVertex(Vertex v);

    void removeVertex(Vertex v);

    void addEdge(Vertex v, Vertex w, Label label);

    bool isEmpty() const;

    std::string toString();
};

struct State {
    std::string name;
    bool isStart;
    bool isAccept;
    State() {
        name = "";
        isStart = false;
        isAccept = false;
    }
    State(std::string name, bool isStart, bool isAccept) {
        this->name = name;
        this->isStart = isStart;
        this->isAccept = isAccept;
    }
};

struct Transition {
    std::string from;
    std::string on;
    std::string to;
    Transition() = default;
    Transition(std::string from, std::string on, std::string to) {
        this->from = from;
        this->on = on;
        this->to = to;
    }
};

struct PairHash {
    std::size_t operator()(const std::pair<std::string, std::string>& p) const {
        return std::hash<std::string>()(p.first) ^ std::hash<std::string>()(p.second);
    }
};

class DFA {
private:
    int numStates;
    int numSymbols;
    std::unordered_map<std::string, State> states;
    std::vector<std::string> symbols;
    std::unordered_map<std::pair<std::string, std::string>, Transition, PairHash> transitions;
public:

    DFA() {
        numStates = 0;
        numSymbols = 0;
    }

    void addState(std::string name, bool isStart, bool isAccept);

    State getState(std::string);

    bool stateExists(std::string);

    int getNumStates() { return numStates; }

    void addSymbol(std::string);

    std::string getSymbol(int index);

    int getNumSymbols() { return numSymbols; }

    bool emptySymbols() { return symbols.empty(); }

    void addTransition(std::string from, std::string on, std::string to);

    Transition getTransition(std::pair<std::string, std::string>);
};

class NFA {

};

class PDA {

};

#endif //MACHINEFUNCTIONS_H



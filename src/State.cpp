#include "State.h"

State::State(int num) {
    n = num;
}

State::~State() {
    //dtor
}

std::vector<Queen> State::get_queens() {
    return queens;
}

int State::get_n() {
    return n;
}

void State::add_queen(Queen q) {
    if(queens.size() < n)
        queens.push_back(q);
}

std::vector<State> State::get_successors() {
    std::vector<State> successors;
    return successors; // mock
}

int State::number_of_attacks() {
    return 0; // mock
}

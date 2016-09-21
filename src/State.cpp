#include <iostream>
#include "State.h"

State::State(int dim) {
    n = dim;
    // initial configuration for the queens on the board
    for(int i = 0; i < n; i++) {
        Queen q(i,i);
        this->add_queen(q);
    }
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
    if((int)queens.size() < n)
        queens.push_back(q);
}

std::vector<State> State::get_successors() {
    std::vector<State> successors;
    return successors; // mock
}

int State::number_of_attacks() {
    return 0; // mock
}

void State::print() {
    char board[n][n];
    // filling board with underlines
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[i][j] = '_';
    // filling board with its queens
    for(int i = 0; i < n; i++)
        board[queens[i].get_x()][queens[i].get_y()] = 'Q';
    // printing
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            std::cout << board[i][j] << (j == n-1 ? "\n" : " ");
}

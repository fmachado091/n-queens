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

/* Gets the list of possible succesors for the state enad returns the best of
 * them (with the smallest number of attacks between two queens. */
State State::best_successor() {
    std::vector<State> successors = get_successors();
    int number_of_successors = successors.size();
    int min_index = 0;
    int min_attacks = 2*n + 1; // given n queens, there is at most 2n attacks
    int attacks;
    for(int i = 0; i < number_of_successors; i++) {
        attacks = successors[i].number_of_attacks();
        if(attacks < min_attacks) {
            min_index = i;
            min_attacks = attacks;
        }
    }
    return successors[min_index];
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

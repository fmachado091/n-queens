#include <iostream>
#include "State.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

State::State() {
    // constructor
}
State::State(int dim) {
    n = dim;
    //initialize random seed
    srand (time(NULL));
    // initial configuration for the queens on the board
    for(int i = 0; i < n; i++) {
        Queen q(rand() % n, i);
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
    if((int)queens.size() < n) {
        queens.push_back(q);
    }
}

std::vector<State> State::get_successors() {
    std::vector<State> successors;
    int x_before, y_before;
    for(int i = 0; i < n; i++) {
        x_before = queens[i].get_x();
        y_before = queens[i].get_y();
        while(queens[i].walk_up(n) != STOP) {
            successors.push_back(*this);
        }
        queens[i].set_x(x_before);
        queens[i].set_y(y_before);
        while(queens[i].walk_down(n) != STOP) {
            successors.push_back(*this);
        }
        queens[i].set_x(x_before);
        queens[i].set_y(y_before);
    }
    return successors;
}

/* Counts number of possible attacks between two queens */
int State::number_of_attacks() {
    // number of attacks in rows
    int attacks_in_rows = 0;
    int queens_by_row[n];
    for(int i = 0; i < n; i++)
        queens_by_row[i] = 0;
    // number of attacks in diagonals
    int attacks_in_diag = 0;
    int queens_by_diagonal[2*n-1], queens_by_diagonal_2[2*n-1];
    for(int i = 0; i < 2*n-1; i++) {
        queens_by_diagonal[i] = 0;
        queens_by_diagonal_2[i] = 0;
    }
    // counting number of attacks
    int x, y;
    for(int i = 0; i < n; i++) {
        x = queens[i].get_x();
        y = queens[i].get_y();
        ++queens_by_row[x];
        ++queens_by_diagonal[x+y];
        ++queens_by_diagonal_2[n-1+y-x];
    }
    // in rows
    for(int i = 0; i < n; i++)
        if(queens_by_row[i] > 1)
            attacks_in_rows += queens_by_row[i] - 1;
    // in diagonals
    for(int i = 0; i < 2*n-1; i++) {
        if(queens_by_diagonal[i] > 1)
            attacks_in_diag += queens_by_diagonal[i] - 1;
        if(queens_by_diagonal_2[i] > 1)
            attacks_in_diag += queens_by_diagonal_2[i] - 1;
    }
    return attacks_in_diag + attacks_in_rows;
}

/* Gets the list of possible succesors for the state enad returns the best of
 * them (with the smallest number of attacks between two queens. */
State State::best_successor() {
    std::vector<State> successors = get_successors();
    int number_of_successors = successors.size();
    std::vector<int> best_successors;
    int min_index;
    int min_attacks = n*n; // more than possible number of attacks
    int attacks;
    for(int i = 0; i < number_of_successors; i++) {
        attacks = successors[i].number_of_attacks();
        if(attacks < min_attacks) {
            min_attacks = attacks;
            best_successors.clear(); // starts again
            best_successors.push_back(i);
        }
        else if(attacks == min_attacks)
            best_successors.push_back(i);
    }
    // chooses random state from possible best states
    srand (time(NULL));
    min_index = rand() % (int)best_successors.size();
    return successors[best_successors[min_index]];
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

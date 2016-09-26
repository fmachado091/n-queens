#include <iostream>
#include "State.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

/* Empty constructor */
State::State() {
    // constructor
}

/* Parameter constructor sets dimension of board */
State::State(int dim) {
    n = dim;
    srand (time(NULL)); //initialize random seed
    // initial configuration for the queens on the board
    for(int i = 0; i < n; i++) {
        Queen q(rand() % n, i); // random row, different columns
        this->add_queen(q);
    }
}

/* Destructor */
State::~State() {
    //dtor
}

/* Getter method for n */
int State::get_n() {
    return n;
}

/* Adds a queen to the list of queens on the board */
void State::add_queen(Queen q) {
    if((int)queens.size() < n) {
        queens.push_back(q);
    }
}

/* Gets all possible successors for a state by making each of the queens on the
 * board vary its row coordinate, but with its column coordinate fixed */
std::vector<State> State::get_successors() {
    std::vector<State> successors;
    int x_before, y_before;
    for(int i = 0; i < n; i++) {
        // initial position
        x_before = queens[i].get_x();
        y_before = queens[i].get_y();
        // each queen walks up on the board as much as it can
        while(queens[i].walk_up(n) != STOP)
            successors.push_back(*this);
        // initial position is set back
        queens[i].set_x(x_before);
        queens[i].set_y(y_before);
        // each queen walks down on the board as much as it can
        while(queens[i].walk_down(n) != STOP)
            successors.push_back(*this);
        // initial position is set back
        queens[i].set_x(x_before);
        queens[i].set_y(y_before);
    }
    return successors;
}

/* Counts number of possible attacks between two queens */
int State::number_of_attacks() {
    // variable for counting number of attacks in rows
    int attacks_in_rows = 0;
    int queens_by_row[n];
    for(int i = 0; i < n; i++)
        queens_by_row[i] = 0;
    // variable for counting number of attacks in diagonals
    int attacks_in_diag = 0;
    int queens_by_diagonal[2*n-1], queens_by_diagonal_2[2*n-1];
    for(int i = 0; i < 2*n-1; i++) {
        queens_by_diagonal[i] = 0;
        queens_by_diagonal_2[i] = 0;
    }
    // counting number of queens
    int x, y;
    for(int i = 0; i < n; i++) {
        x = queens[i].get_x();
        y = queens[i].get_y();
        ++queens_by_row[x]; // in each row
        ++queens_by_diagonal[x+y]; // in each antidiagonal direction
        ++queens_by_diagonal_2[n-1+y-x]; // in each main diagonal direction
    }
    // number of attacks in rows
    for(int i = 0; i < n; i++)
        if(queens_by_row[i] > 1)
            attacks_in_rows += queens_by_row[i] - 1;
    // number of attacks in diagonals
    for(int i = 0; i < 2*n-1; i++) {
        if(queens_by_diagonal[i] > 1)
            attacks_in_diag += queens_by_diagonal[i] - 1;
        if(queens_by_diagonal_2[i] > 1)
            attacks_in_diag += queens_by_diagonal_2[i] - 1;
    }
    return attacks_in_diag + attacks_in_rows;
}

/* Gets the list of possible succesors for the state and returns the best of
 * them (with the smallest number of attacks between two queens) */
State State::best_successor() {
    std::vector<State> successors = get_successors();
    int number_of_successors = successors.size();
    std::vector<int> best_successors;
    int min_index; // index for best successor
    int min_attacks = n*n; // number of attacks for best successor
    int attacks;
    for(int i = 0; i < number_of_successors; i++) {
        attacks = successors[i].number_of_attacks();
        if(attacks < min_attacks) { // finds a new minimum
            min_attacks = attacks;
            best_successors.clear(); // starts vector again
            best_successors.push_back(i); // adds new minimum
        }
        else if(attacks == min_attacks) // finds the same minimum again
            best_successors.push_back(i); // adds to list of best successors
    }
    // chooses random state from possible best states
    srand (time(NULL)); // initialize random seed
    min_index = rand() % (int)best_successors.size();
    return successors[best_successors[min_index]];
}

/* Prints board on screen */
void State::print() {
    char board[n][n];
    // filling board with underlines
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[i][j] = '_';
    // filling board with its queens
    for(int i = 0; i < n; i++)
        board[queens[i].get_x()][queens[i].get_y()] = 'Q';
    // actually printing
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            std::cout << board[i][j] << (j == n-1 ? "\n" : " ");
}

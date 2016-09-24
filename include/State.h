#ifndef STATE_H
#define STATE_H

#include "Queen.h"
#include <vector>

class State
{
    public:
        State();
        State(int);
        virtual ~State();
        std::vector<Queen> get_queens();
        void add_queen(Queen); // adds queen to list of queens on the board
        std::vector<State> get_successors(); // possible successors for state
        State best_successor(); // best of the possible successors for state
        int number_of_attacks(); // number of possible attacks between 2 queens
        int get_n();
        void print(); // print board on screen
        /*void set_board(char**);
        int* get_queens_by_diagonal() { return queens_by_diagonal; };*/
    protected:
    private:
        std::vector<Queen> queens; // list of queens on the board
        int n; // dimension of the board
        /*int* queens_by_row;
        int* queens_by_diagonal;
        int* queens_by_diagonal_2;*/
};

#endif // STATE_H

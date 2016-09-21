#ifndef STATE_H
#define STATE_H

#include "Queen.h"
#include <vector>

class State
{
    public:
        State(int);
        virtual ~State();
        std::vector<Queen> get_queens();
        void add_queen(Queen); // adds queen to list of queens on the board
        std::vector<State> get_successors(); // possible successors for state
        int number_of_attacks(); // number of possible attacks between 2 queens
        int get_n();
        void print(); // print board on screen
    protected:
    private:
        std::vector<Queen> queens; // list of queens on the board
        int n; // dimension of the board
};

#endif // STATE_H

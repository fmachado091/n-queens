#include <iostream>
#include "Queen.h"
#include "State.h"

#define MAX_ITERATIONS 10000

using namespace std;

State initialize_problem(int n) {
    State initial_state(n);
    for(int i = 0; i < n; i++) {
        Queen q(i,i);
        initial_state.add_queen(q);
    }
    return initial_state;
}

State min_value_successor(vector<State> successors) {
    return successors[0]; // mock
}

State Hillclimb(State current) {
    int n = current.get_n();
    State next(n);
    int iteration = 1;
    vector<State> successors;
    while(iteration <= MAX_ITERATIONS) {
        successors = current.get_successors();
        next = min_value_successor(successors);
        if(current.number_of_attacks() <= next.number_of_attacks())
            return current;
        current = next;
        ++iteration;
    }
    return State(0);
}

void print_solution(State final_state) {
    // mock
}

int main() {
    int dim;
    cout << "Escolha a dimensao do tabuleiro: ";
    cin >> dim;
    State initial_state = initialize_problem(dim);
    State solution = Hillclimb(initial_state);
    if(solution.get_n() == 0)
        cout << "Erro" << endl;
    else
        print_solution(solution);
    return 0;
}

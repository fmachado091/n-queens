#include <iostream>
#include "Queen.h"
#include "State.h"

#define MAX_ITERATIONS 10000

using namespace std;

State Hillclimb(State current) {
    int n = current.get_n();
    State next(n);
    int iteration = 1;
    vector<State> successors;
    while(iteration <= MAX_ITERATIONS) {
        next = current.best_successor();
        if(current.number_of_attacks() <= next.number_of_attacks())
            return current;
        current = next;
        ++iteration;
    }
    return State(0);
}

int main() {
    int dim;
    cout << "Escolha a dimensao do tabuleiro: ";
    cin >> dim;
    State initial_state(dim);
    initial_state.print();
    /*State solution = Hillclimb(initial_state);
    if(solution.get_n() == 0)
        cout << "Erro" << endl;
    else
        print_solution(solution);*/
    return 0;
}

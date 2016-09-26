#include <iostream>
#include "Queen.h"
#include "State.h"

using namespace std;

/* Hillclimb algorithm for finding the state with minimum number of attacks */
State Hillclimb(State current) {
    State next;
    int iteration = 1; // counts number of iterations
    while(true) { // unless an error occurs, the program always find a solution
        next = current.best_successor();
        if(current.number_of_attacks() <= next.number_of_attacks()) {
            cout << "\nNumber of iterations: " << iteration << endl;
            return current;
        }
        current = next;
        ++iteration;
    }
    // in case of error
    return State(-1);
}

int main() {
    int dim;
    cout << "Choose the board's dimension: ";
    cin >> dim;
    State initial_state(dim);
    cout << "\nInitial state:\n" << endl;
    initial_state.print();
    State solution = Hillclimb(initial_state);
    cout << "\nFinal state:\n" << endl;
    if(solution.get_n() == -1)
        cout << "Error" << endl;
    else {
        solution.print();
        cout << "\nNumber of attacks: " << solution.number_of_attacks() << endl;
    }
    return 0;
}

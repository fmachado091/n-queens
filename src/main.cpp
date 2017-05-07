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
            //cout << "\nNumber of iterations: " << iteration << endl;
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
    State solution = Hillclimb(initial_state);
    // if it doesn't find solution, then get a new random initial state
    // and try again
    while(solution.number_of_attacks() > 0) {
        State initial_state(dim);
        solution = Hillclimb(initial_state);
    }
    cout << "\nSolution:\n" << endl;
    if(solution.get_n() == -1)
        cout << "Error" << endl;
    else {
        solution.print();
        //cout << "\nNumber of attacks: " << solution.number_of_attacks() << endl;
    }
    /* Just so the program doesn't quit immediately after its execution
    string str;
    cin >> str;*/
    return 0;
}

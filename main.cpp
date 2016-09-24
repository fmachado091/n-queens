#include <iostream>
#include "Queen.h"
#include "State.h"

using namespace std;

State Hillclimb(State current) {
    State next;
    int iteration = 1;
    while(true) {
        next = current.best_successor();
        if(current.number_of_attacks() <= next.number_of_attacks()) {
            cout << "number of iterations: " << iteration << endl;
            return current;
        }
        current = next;
        ++iteration;
    }
    return State(-1);
}

int main() {
    int dim;
    cout << "Escolha a dimensao do tabuleiro: ";
    cin >> dim;
    State initial_state(dim);
    initial_state.print();
    cout << endl;
    State solution = Hillclimb(initial_state);
    cout << "\nfinal:" << endl;
    if(solution.get_n() == -1)
        cout << "Erro" << endl;
    else {
        solution.print();
        cout << "\nnumero ataques: " << solution.number_of_attacks() << endl;
    }
    return 0;
}

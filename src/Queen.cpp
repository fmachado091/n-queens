#include "Queen.h"

/* Constructor */
Queen::Queen(int coord_x, int coord_y) {
    x = coord_x;
    y = coord_y;
}

/* Destructor */
Queen::~Queen() {
    //dtor
}

/* Getter method for x */
int Queen::get_x() {
    return x;
}

/* Getter method for y */
int Queen::get_y() {
    return y;
}

/* Setter method for x */
void Queen::set_x(int coord_x) {
    x = coord_x;
}

/* Setter method for y */
void Queen::set_y(int coord_y) {
    y = coord_y;
}

/* If possible, then queen takes one step up on the board */
int Queen::walk_up(int n) {
    if(x > 0) {
        --x;
        return GO_ON;
    }
    return STOP;
}

/* If possible, then queen takes one step down on the board */
int Queen::walk_down(int n) {
    if(x < n-1) {
        ++x;
        return GO_ON;
    }
    return STOP;
}

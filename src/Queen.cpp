#include "Queen.h"

Queen::Queen(int coord_x, int coord_y) {
    x = coord_x;
    y = coord_y;
}

Queen::~Queen()
{
    //dtor
}

int Queen::get_x() {
    return x;
}

int Queen::get_y() {
    return y;
}

void Queen::set_x(int coord_x) {
    x = coord_x;
}

void Queen::set_y(int coord_y) {
    y = coord_y;
}

int Queen::walk_up(int n) {
    if(y < n-1) {
        ++y;
        return GO_ON;
    }
    return STOP;
}

int Queen::walk_down(int n) {
    if(y > 0) {
        --y;
        return GO_ON;
    }
    return STOP;
}

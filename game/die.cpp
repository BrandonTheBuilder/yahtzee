#include "die.h"

Die::Die(int n) {
    srand (time(NULL));
    sides = n;
}

int Die::roll () {
    return rand() % sides + 1;
}
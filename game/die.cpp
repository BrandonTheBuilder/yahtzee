#include "die.h"

Die::Die(int n) {
    sides = n;
}

int Die::roll () {
    return rand() % sides + 1;
}
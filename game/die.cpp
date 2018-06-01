#include "die.h"

int Die::roll () {
    return rand() % _sides + 1;
}

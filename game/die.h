#include <stdlib.h>     /* srand, rand */
#include <time.h> 

// Class to represent a die of n sides.
class Die {
public:
    Die(int n):_sides(n) {} 
    int roll(){ return rand() % _sides + 1; } 
private:
    int _sides;
};

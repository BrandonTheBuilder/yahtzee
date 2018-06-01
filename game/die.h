#include <stdlib.h>     /* srand, rand */
#include <time.h> 

// Class to represent a die of n sides.
class Die {
public:
    Die(int n):_sides(n) {} 
    int roll();
private:
    int _sides;
};

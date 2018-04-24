#include <stdlib.h>     /* srand, rand */
#include <time.h> 

// Class to represent a die of n sides.
class Die {
public:
    Die(int n);
    ~Die() {}
    int roll();
private:
    int sides;
};

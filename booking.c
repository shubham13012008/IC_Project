#include "train.h"
#include <time.h>

int generatePNR() {
    srand(time(0));
    return rand() % 900000 + 100000; // to create a random number that we can use as pnr
}
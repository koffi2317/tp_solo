#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nb_aleatoire(int min, int max) {
    return min + (int) (rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

int main(void)
{



    return 0;
}

#include "deez.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    if (argc == 1)
    {
        fprintf(stderr, "No input file provided\n");
        exit(EXIT_FAILURE);
    }

    deez_compile(argv[1]);
    return 0;
}


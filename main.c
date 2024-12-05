#include <stdio.h>
#include <stdlib.h>
#include "lab.h"

int main(int argc, char **argv)
{
        if (!CheckingMistake(argc, argv));
        {
                return 1;
        }

        int len = (argc - 2) / 3;
        int *results = (int*)malloc(len * sizeof(int));
        if (results == NULL)
        {
                printf("Memory fail\n");
                return 1;
        }

        calculate(argc, results, argv, len);
        int k = atoi(argv[argc - 1]);
        decryption(results, len, k);

        free(results);
        return 0;
}


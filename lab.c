#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <iso646.h>
#include "lab.h"

bool CheckingNumber(char *el)
{
        int i = 0;
        if ((el[0] == '+') or (el[0] == '-')) i++;
        for (; i < strlen(el); i++)
        {
                if (!isdigit(el[i]))
                {
                        return 0;
                }
        }
        return 1;
}

bool CheckingMistake(int argc, char **argv)
{
        if (argc % 3 != 0)
        {
                printf("\033[1;31m!!Mistake! no arguments\033[1;0m\n");
                return 0;
        }

        if (strcmp(argv[argc - 2], "-k") != 0)
        {
                printf("\033[1;31m!!!Mistake! Wrong flag or no flag\033[1;0m\n");
                return 0;
        }

        if (!CheckingNumber(argv[argc - 1]))
        {
                printf("\033[1;31m!!!Mistake! Wrong modifier k\033[1;0m\n");
                return 0;
        }

        for (int i = 1; i < argc - 2; i = i + 3)
        {
                if (!CheckingNumber(argv[i]))
                {
                        printf("\033[1;31m!!!Mistake! Element № %d is not number\033[1;0m\n", i);
                        return 0;
                }

                if ((argv[i + 1][0] != '+' and argv[i + 1][0] != '-' and argv[i + 1][0] != '*' and argv[i + 1][0] != '%') or strlen(argv[i + 1]) != 1)
                {
                        printf("\033[1;31m!!!Mistake! Wromg operator in element № %d\033[1;0m\n", (i / 3) + 1);
                        return 0;
                }

                if (argv[i + 1][0] == '%' and atoi(argv[i + 2]) == 0)
                {
                        printf("\033[1;31m!!!Mistake! Wrong dividing numbers\033[1;0m\n");
                        return 0;
                }

                if (CheckingNumber(argv[i + 2]))
                {
                        printf("\033[1;31m!!!Mistake! Element № %d is not number\033[1;0m\n", i + 2);
                        return 0;
                }
        }
        return 1;
}

void calculate(int argc, int *arr, char **argv, int len) {
    int a;
    int b;
    for (int i = 1, k = 0; i < argc - 2; i += 3, k++) {
        a = atoi(argv[i]);
        b = atoi(argv[i + 2]);

        switch (argv[i + 1][0]) {
            case '+':
                arr[k] = a + b;
                break;

            case '-':
                arr[k] = a - b;
                break;

            case '*':
                arr[k] = a * b;
                break;

            case '%':
                arr[k] = a % b;
                break;
        }
        printf("Answer is #%d: %d\n", k + 1, arr[k]);
    }
}

void decryption(int *arr,int len, int g)
{
        printf("Result string: \e[0;32m");
        for(int r = 0; r < len; r++)
        {
                printf("%c", (char)(arr[r] - g));
        }
        printf("\n");
}

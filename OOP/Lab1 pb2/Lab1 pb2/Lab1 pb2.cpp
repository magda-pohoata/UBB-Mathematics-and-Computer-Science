// Lab1 pb2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char d1, d2, d3, d4;
    for (d1 = 9; d1 >= 3; d1--)
    {
        for (d2 = d1 - 1; d2 >= 2; d2--)
        {
            for (d3 = d2 - 1; d3 >= 1; d3--)
            {
                d4 = 24 - d1 - d2 - d3;
                if (d4 >= 0 && d4 < d3)
                    printf("%d%d%d%d %c \n", d1, d2, d3, d4,3);
            }

        }
    }

    //output
}

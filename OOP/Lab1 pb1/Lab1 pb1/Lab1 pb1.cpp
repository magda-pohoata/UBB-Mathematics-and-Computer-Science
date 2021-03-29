
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main()
{
    //input
    char name[20];   //tablou de caractere
    int favNr;
    printf("whats ur name? \n");

    //citire cu spatii
    //getline c++
    //gets c

    //scanf("%s", name);

    gets_s(name);
    printf("whats ur favorite number? \n");
    scanf("%d", &favNr);

    printf("\nWelcome, %s to Jurassic Park!\n", name);
    printf("You are a %d /10!!! \n", favNr);
    return 0;
}

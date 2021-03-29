

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
    int n;
    scanf("%d", &n);
    char text[100];
    gets_s(text);
    gets_s(text);

    int ln = strlen(text);
    for (int i = 0; i <= ln; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            int letter = text[i] - 'a';
            if (letter - n >= 0)
                text[i] = text[i] - n;
            else
                text[i] = text[i] + (26 - n % 26);
        }
        if (text[i] >= 'A' and text[i] <= 'Z')
        {
            int letter = text[i] - 'A';
            if (letter - n >= 0)
                text[i] = text[i] - n;
            else
                text[i] = text[i] + (26 - n % 26);
        }
    }

    printf("%s", text);

    return 0;
}

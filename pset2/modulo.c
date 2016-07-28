#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string b = "bacon";
    int c = strlen(b);
    for (int a = 0; a < c; a++){
        printf("%c\n", ((b[a] + 2 - 97) % 26) + 97);
    
    }
}
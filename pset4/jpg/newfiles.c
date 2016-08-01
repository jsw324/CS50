#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char buffer[50];
    
    int course = 50;
    
    sprintf(buffer,"CS%d rocks!", course);
    
    printf("%s\n", buffer);
}
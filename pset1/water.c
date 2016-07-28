#include <cs50.h>
#include <stdio.h>

int PositiveInt();

int main(void)
{
    int n = PositiveInt();
    n = n * 192;
    n = n / 16;
    printf("Your showers use the equivalent of %i bottles of water!\n", n);
    return 0;
}

/**
 * Gets a positive integer from a user.
 */
int PositiveInt(void)
{
    int n;
    do
    {
        printf("How many minutes are your showers? ");
        n = GetInt();
    }
    while (n < 1);
    return n;
}
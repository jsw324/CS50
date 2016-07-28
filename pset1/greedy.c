#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    
    float c;
    int change = 0;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    
    do {
    printf("O hai! How much change is owed? ");
    c = GetFloat();
    } while (c < 0);
    
    change = round(c * 100);
    
   while (change >= 25) {
       
       quarters = round(change / 25);
       change = round(change - (quarters * 25));
       
       //printf("quarters %ichange %i\n",quarters, change);
       
   }
   while (change >= 10) {
       
       dimes = change / 10;
       change = change % 10;
       
       //printf("dimes %i leftover %i\n", dimes, change);
   }
   while (change >= 5) {
       
       nickels = change / 5;
       change = change % 5;
       
       //printf("nickels %i leftover %i\n", nickels, change);
   }
   while (change >= 1) {
       
       pennies = change / 1;
       change = change % 1;
       //printf("pennies %i change %i\n", pennies, change);
       
   }
   
   change = quarters + dimes + nickels + pennies;
   printf("%i\n", change);

    return 0;
}
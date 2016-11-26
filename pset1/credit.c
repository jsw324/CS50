#include <stdio.h>
#include <cs50.h>
#include "helpers.c"


//hello
long int right_digit = 0;
int number = 0;
int counter = 0;
long int even = 0;
long int odd = 0;
long int num = 0;
string cardType = "";
int oddTotal;

bool tot;

int main(void)
{
    int total = 0;
    
    printf("Please enter your credit card number: \n");
    long int cc = GetLongLong();
    
    cardType = TypeOfCard(cc);
    //printf("%s\n", cardType);
    
    //seperate cc# to every other digit
    while ( cc != 0 ) { 
        
        right_digit = cc % 10; 
        cc = cc / 10;
            //even digits get added together
            if (counter % 2 == 0) {
                
                even = even + right_digit;
                
                //printf("0: %li\n",right_digit);
                
                counter++;
                
            } else {
                
                 counter++;
                //check if odd digit will bo over 10 if mult. by 2
                if (right_digit * 2 >= 10) {
                    //if yes, seperate digits and add together
                    right_digit = right_digit * 2;
                    oddTotal = oddTotal + (right_digit % 10) + (right_digit / 10);
                    //printf("odd %li\n", odd);
                    
                } else {
                //add odd digits together
                oddTotal = oddTotal + (right_digit * 2);
                //printf("1: %li\n", right_digit);
                
               
            }
        
        }
            // add odd and even numbers together for total
            total = oddTotal + even;
            tot = isValid(total);
            //printf("%d\n", tot);
    }
    // if number is valid check if card type is valid
    if (tot == 1){
        
        printf("%s\n", cardType);
    } else {
        printf("INVALID\n");
    }
    return 0;
}
//check type of card and if card is valid
string TypeOfCard(long int cc) {
    
    
    if (cc > 340000000000000 && cc < 380000000000000) {
        
        cardType = "AMEX";
        return cardType;
        
    } else if (cc > 5100000000000000 && cc < 5600000000000000) {
        
        cardType = "MASTERCARD";
        return cardType;
    } else if ((cc > 4000000000000 && cc < 5000000000000) || (cc > 4000000000000000 && cc < 5000000000000000)) {
        
        cardType = "VISA";
        return cardType;
    } else {
        
        cardType = "INVALID";
        return cardType;
    }
}
//do digits follow Luhn's algorithm.
bool isValid(total){
    
    if (total % 10 == 0) {
        return true;
    } else {
        return false;
    }
}


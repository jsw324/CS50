#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string s;

int main(int argc, string argv[])
{
    if (argc < 2) {
        printf("Please enter a command line value.\n");
        return 1;
    }
    
    int k = atoi(argv[1]);
    s = GetString();

    if (k < 0){
        printf("Your number must be a positive integer.  Try again");
        return 1;
    }
    
    for(int i = 0; i < strlen(s); i++){
        if (s[i] == 32){
            printf(" ");
        } else if (isalpha(s[i]) && islower(s[i])){
                printf("%c",  (((s[i] + k - 97) % 26) + 97));
        } else if (isalpha(s[i]) && isupper(s[i])){
                printf("%c",  (((s[i] + k - 65) % 26) + 65));
        } else {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}
                
     
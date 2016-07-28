#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string p;

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2){
        printf("You must enter a word as command line argument\n");
        return 1;
    } 

    string k = argv[1];
    
    for (int a = 0; a < strlen(k); a++){
        if(!isalpha(k[a])){
            printf("character must be a letter\n");
            return 1;
        } else {
            k[a] = tolower(k[a]);
        }
    }
    
    p = GetString();
   int o = strlen(k);
   int r = 0;

    for(int i = 0; i < strlen(p); i++){
        if(isalpha(p[i]) && islower(p[i])){
            r = r % o;
            printf("%c", (((p[i] + tolower((k[r] - 97))) - 97) % 26) + 97);
            r++;
            
        }else if(isalpha(p[i]) && isupper(p[i])){
             r = r % o;
            printf("%c", (((p[i] + (k[r] - 97)) - 65) % 26) + 65);
            r++;
        } else {
            printf("%c", p[i]);
        }
    }
    printf("\n");
    return 0;
    
}

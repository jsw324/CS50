#include <stdio.h>
#include <cs50.h>
#include <string.h> 
#include <ctype.h>

int main(void)
{
    string n;

    n = GetString();
    int l = strlen(n);
    int a = 0;
    int c = 0;
    int e = 0;
    
    for (int x = 0; x < l; x++) {
        //printf("%c\n", n[x]);
        if (n[x] == 32){
            a++;
        }
    }
    if (a == 0){
        printf("%c\n", toupper(n[0]));
    }
    
    if (a == 1){
        for (int b = 0; b < l; b++) {
            if (n[b] == 32) {
                printf("%c%c\n", toupper(n[0]), toupper(n[b + 1]));
            } 
        }
    }
    if (a == 2){
        for (c = 0; c < l; c++){
            if (n[c] == 32){
                printf("%c%c", toupper(n[0]), toupper(n[c + 1]));
                break;
            } 
        }
        for (int d = 0; d < l; d++) {
            if (n[d] == 32) {
                e = d;
            }
        }
        printf("%c\n", toupper(n[e + 1]));
    }
     
}

   
  
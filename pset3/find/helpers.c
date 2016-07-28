/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"


/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    int midpoint = values[n/2];
    
    if (values[midpoint] > value){
        for (int i = midpoint; i < n; i++) {
            if (values[i] == value){
                return 1;
            }
        }
    } else if(values[midpoint] < value){
        for(int b = 0; b < (midpoint -1); b++){
            if (values[b] == value){
                return 1;
            }
        }
    } else {
        return 0;
    }
    return 0;
}
    




    //linear search solution
    /*
    for(int i = 0; i < n; i++){
        if(values[i] == value){
            return true;
        }
    }
    
    return false;
}
*/
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int c = 1;
    do {
        c = 0;
        for(int i = 0; i < (n -1); i++){
            printf(" i is %i\n", i);
            for(int b = i + 1; b < i + 2; b++){
                printf("b is %i\n", b);
                printf("i %i b %i\n", values[i], values[b]);
                if(values[b] < values[i]){
                    int temp = values[i];
                    values[i] = values[b];
                    values[b] = temp;
                    printf("changes? i %i b %i\n", values[i], values[b]);
                    c++;
                }
            }
        }
    } while(c > 0);
    for(int c = 0; c < n; c++){
        printf("%i\n", values[c]);
    }
}


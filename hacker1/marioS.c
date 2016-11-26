#include <stdio.h>
#include <cs50.h>

//prototype

string HowManyHashes(int);

int main(void)
{
  int height;
  //int s = 0;
  int sp;
 
  do {
    printf("Height: ");
    height = GetInt();
  } 
  while (height < 0 || height > 23);

  for (int i = 1; i < height + 1; i++) {
    //left pyramid spaces
    for (sp = 0; sp < height - i; sp++) {
      printf(" ");
    }
  //left pyramid hashes
    for (int ha = 0; ha < i; ha++) {
      printf("#");
    }
  printf("  ");
    
      //right pyramid hashes
    for (int h = 0; h < i; h++) {
        
      printf("#");
  }
   /*// rihgt pyramid spaces
   for (s = 0; s < height - i - 1; s++) {
    
      printf(" ");
      
  }
  */
    printf("\n");
  }
  return 0;
}
 



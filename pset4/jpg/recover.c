/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
        
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  FILE* inptr = fopen("card.raw", "r");
  
  unsigned char buffer[512];
  
  char jpgname = NULL:
  
  while(fread(buffer, 512, 1, inptr) == 1)
  {
    if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] == 0xe0) || (buffer[3] == 0xe1)))
    {
      printf("found one\n");
    }
  }
}
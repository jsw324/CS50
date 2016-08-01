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
#include <cs50.h>

//prototype getJpegName();

int main(void)
{
  FILE* inptr = fopen("card.raw", "r");
  
  unsigned char buffer[512];
  
  char jpgName[50];
  int jpgCounter = 0;
  
  
  while(fread(buffer, 512, 1, inptr) == 1)
  {
    FILE* outptr = fopen(jpgName, "w");
    if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] == 0xe0) || (buffer[3] == 0xe1)))
    {
      if(jpgCounter < 10)
      {
        sprintf(jpgName, "00%d.jpg", jpgCounter);
      } else {
        sprintf(jpgName, "0%d.jpg", jpgCounter);
      }
      if((buffer[0] != 0xff) && (buffer[1] != 0xd8) && (buffer[2] != 0xff) && ((buffer[3] != 0xe0) || (buffer[3] != 0xe1)) && (jpgCounter != 0)) 
      {
        outptr = fopen(jpgName, "a");
        fwrite(buffer, 512, 1, outptr);
      }
      else 
      {
        fclose(outptr);
        jpgCounter++;
      }
    }
  }
}

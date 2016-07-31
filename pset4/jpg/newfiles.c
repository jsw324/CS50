#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
   // printf("digame: ");
    
    //string input = GetString();
    
    FILE* inptr = fopen("card.raw", "r");
    
    FILE* outptr = fopen("newfile.txt", "w");
      
    char content[sizeof(inptr)];
    
   // fread(content, sizeof(test), 1, test);
    
    while(fread(content, sizeof(inptr), 1, inptr) == 1)
    {
        for(int i = 0; i < sizeof(inptr); i++)
        {
            printf("%s\n", (content + i));
            if (strcmp((content + i), "0xff") == 0 && strcmp((content + i + 1), "0xd8") == 0 )
            {
                printf("%c\n", *(content + i));
                fwrite(content, sizeof(inptr), 1, outptr);
            }
        }
    }
}
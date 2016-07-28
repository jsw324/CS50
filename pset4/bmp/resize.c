/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }
    
    

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    int size = atoi(argv[1]);
    
    if (size < 1 || size > 100) {
        printf("Not within range");
        return 2;
    }

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
  
   
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    //save original width and height and increase by variable size
    int origWidth = bi.biWidth;
    int origHeight = bi.biHeight;
    bi.biWidth = bi.biWidth * size;
    bi.biHeight = bi.biHeight * size;
    
    // determine padding for scanlines
    int origPadding = (4 - (origWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
     //need biSizeImage to be resized as well
    
    bi.biSizeImage = abs(bi.biHeight) * (bi.biWidth * sizeof(RGBTRIPLE)) + padding;
    bf.bfSize = (bi.biSizeImage + 54);
    
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

   


    // iterate over infile's scanlines
    for (int i = 0; i < abs(origHeight); i++)
    {
        for (int n = 0; n < size; n++){
            //skip padding
            fseek(inptr, (54 + ((origWidth * 3 + origPadding) * i)), SEEK_SET);
            
            // iterate over pixels in scanline
             for (int j = 0; j < origWidth; j++)
            {
            
                // temporary storage
                RGBTRIPLE triple;
 

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // write RGB triple to outfile
                for (int b = 0; b < size; b++){
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
        }
     //   // skip over padding, if any
       // fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}

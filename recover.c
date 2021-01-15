#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
//STEP 1___________________________________________

    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }
//__________________________________________________

//STEP 2____________________________________________

    //Open the memory card
    FILE *memoryCard = fopen(argv[1], "r");
    if (memoryCard == NULL)
    {
        printf("Cannot open your file\n");
        return 1;
    }

    typedef uint8_t BYTE;                           //defined the new data type BYTE which is 8 bit long

    BYTE buffer[512];                               //defined buffer to which will store 512 byte per once from the memory card

    int JPEG_count = 0;                             //defined the number of JPEG found

    FILE *recovered_JPEG = NULL;                    //initialize the final output file

    char *filename = malloc(8 * sizeof(char));      //initialize the file name array which will store the header of each JPEG

//__________________________________________________

//STEP 3____________________________________________

    //loop memory card
    while (fread(&buffer, sizeof(BYTE), 512, memoryCard) >= 1)
    {

        //check the start of JPEG in each 512-byte-block
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", JPEG_count);      //name the file and add into filename array : 001.jpg 002.jpg etc...

            recovered_JPEG = fopen(filename, "w");           //open file to write

            JPEG_count++;                                   //count image
        }

        //write all of the data stored in buffer into output file
        if (recovered_JPEG != NULL)
        {
            fwrite(&buffer, sizeof(BYTE), 512, recovered_JPEG);
        }
    }
//__________________________________________________

    //close all the files we have opened

    free(filename);             //free malloc

    fclose(memoryCard);         //close memory card

    fclose(recovered_JPEG);     //close all the output file

    return 0;
}

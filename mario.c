#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Function to ask and check the received height value
    int height;
    do
    {
        height = get_int("Height:");
    }
    while (height < 1 || height > 8);;

    // Function to draw the pyramid
    // For each row
    for (int i = 0; i < height; i++)
    {
        // For each column
        for (int j = 0; j < height; j++)
        {
            //Printing the height
            if (i + j < height - 1)
            {
                printf(" ");
            }

            else
            {
                printf("#");
            }
        }

        // Move to the next line
        printf("\n");
    }
}

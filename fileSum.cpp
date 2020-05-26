#include <stdio.h>
#include <stdlib.h>
 
// file named 'data.txt' in the same working directory containing:
// 5 15 12 38 97 72 59 60 25 71
 
int main(void)
{
    int* numbers; // points to an array of (infinite) integers
 
    FILE* input_file = NULL; // input file stream
   
    input_file = fopen("data.txt", "r");
   
    if (input_file == NULL)
    {
        printf("Error: Could not open file.\n");
        return -1;
    }
   
    int count;
    if (fscanf(input_file, "%d", &count) != 1)
    {
        printf("Error: Could not read 'count'.\n");
       
        return -1;
    }
    // allocate required memory for the array
    numbers =(int *)calloc(1, sizeof(int) * count);
    //numbers = (int *)malloc(count * sizeof(int));
    if (numbers == NULL)
    {
        printf("Error: Could not allocate memory.\n");
        return -1;
    }

    for (int c = 0; c < count; c++)
    {
        if (fscanf(input_file, "%d", &numbers[c]) != 1)
        {
            printf("Error: Could not read number.\n");
            break;
        }
    }
 
    for (int c = 0; c < count; c++)
        printf("numbers[%d]: %d\n", c, numbers[c]);
       
    int sum = 0;
 
    for (int c = 0; c < count; c++)
        sum += numbers[c];
   
    printf("Sum: %d\n", sum);
   
    fclose(input_file);
    
    free(numbers);
}
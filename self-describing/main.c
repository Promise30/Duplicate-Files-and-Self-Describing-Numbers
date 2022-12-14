#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int self_describing(int number);
int countOccurence(int number, int singleInt);

int main()
{
    int testCases, num, numLength;
    // PROGRAM TO OPEN AND READ THE FILE
    FILE *file;
    file = fopen("input.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // READ NUMBER OF TEST CASES
    fscanf(file, "%d", &testCases);
    printf("%d\n", testCases);

    // LOOP THROUGH EACH TEST CASE AND PASS IT THROUGH THE SELF_DESCRIBING FUNCTION TO RETURN AN OUTPUT
    for (int i = 0; i < testCases; i++)
    {
        fscanf(file, "%d", &num);

        int result;
        result = self_describing(num);
        if (result == 1)
        {
            printf("Self Describing number\n");
        }
        else
        {
            printf("Not self describing\n");
        }
    }
    fclose(file);
    return 0;
}

int self_describing(int number)
{

    char strNum[100];
    int strLength;
    int number_array[100];

    // CONVERTING THE NUMBER TO STRING TO GET THE LENGTH
    sprintf(strNum, "%d", number);
    strLength = strlen(strNum);

    int digitsList[strLength];

    // LOOP THROUGH EACH VALUE IN THE NUMBER AND STORE AS A SINGLE DIGIT OF INT IN THE ARRAY
    for (int index = 0; index < strLength; index++)
    {
        number_array[index] = strNum[index] - '0';
    }

    // STORE A RANGE OF DIGITS 0-<length of the string Number and store the value in an arrsy
    for (int digit = 0; digit < strLength; digit++)
    {
        digitsList[digit] = digit;
    }

    // CONVERT THE STRING NUMBER BACK TO AN INTEGER
    int strToNum = atoi(strNum);

    int countDigits[strLength];
    int value;
    // printf("Printing value of the result of count occurence function: ");
    for (int a = 0; a < strLength; a++)
    {
        value = countOccurence(strToNum, digitsList[a]);
        // printf("%d \n", value);
        countDigits[a] = value;
    }
    // LOOPING THROUGH THE VALUE OF THE ARRAY CONTAINING OUTPUT WHEN PASSED THROUGH COUNTOCCURENCE FUNCTION
    /*for(int c=0; c < strLength; c++){
        printf("Output: %d\n", )
    }*/
    // CONVERT THE FIRST ARRAY CONTAINING SINGLE DIGITS INTO A SINGLE WHOLE VALUE
    int var1, var2 = 0;
    for (var1 = 0; var1 < strLength; var1++)
    {
        var2 = 10 * var2 + number_array[var1];
    }

    // CONVERT THE SECOND ARRAY CONTAINING SINGLE DIGITS INTO A SINGLE WHOLE VALUE
    int var3, var4 = 0;
    for (var3 = 0; var3 < strLength; var3++)
    {
        var4 = 10 * var4 + countDigits[var3];
    }
    // printf("%d\n", var4);

    if (var2 != var4)
    {
        return 0;
    }
    return 1;
}

int countOccurence(int intNumber, int singleInt)
{
    if (intNumber <= 0)
    {
        return 0;
    }

    int remainder = intNumber % 10;

    if (remainder == singleInt)
    {
        return 1 + countOccurence(intNumber / 10, singleInt);
    }
    return countOccurence(intNumber / 10, singleInt);
}

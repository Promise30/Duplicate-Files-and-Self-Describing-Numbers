#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    int testcases;
    int numOfFiles;

    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error, File is empty!");
        exit(0);
    }

    fscanf(fp, "%d", &testcases);

    for (int a = 0; a < testcases; a++)
    {
        fscanf(fp, "%d", &numOfFiles);
        char file_names[numOfFiles][50];
        int files_id[numOfFiles];

        for (int b = 0; b < numOfFiles; b++)
        {
            int idNew;
            char file_name[50];
            fscanf(fp, "%s", file_name);
            int existingFile;

            for (int c = 0; c < numOfFiles; c++)
            {
                if (!strcmp(file_names[c], file_name))
                {
                    existingFile = c;
                    break;
                }
                else
                {
                    existingFile = -1;
                }
            }

            fscanf(fp, "%d", &idNew);

            if (existingFile == -1)
            {
                strcpy(file_names[b], file_name);
                files_id[b] = idNew;
            }
            else
            {
                if (files_id[existingFile] <= idNew)
                {
                    strcpy(file_names[b], file_name);
                    files_id[b] = -1;
                }
                else
                {
                    strcpy(file_names[b], file_name);
                    files_id[existingFile] = idNew;
                    files_id[b] = -1;
                }
            }
        }

        // loop to sort the file ids stored, in an ascending order
        int sortId;
        for (int i = 0; i < numOfFiles; i++)
        {
            for (int k = i + 1; k < numOfFiles; k++)
            {
                if (files_id[i] > files_id[k])
                {
                    sortId = files_id[i];
                    files_id[i] = files_id[k];
                    files_id[k] = sortId;
                }
            }
        }

        // loop to print the file ids
        for (int x = 0; x < numOfFiles; x++)
        {
            if (files_id[x] != -1)
            {
                printf("%d\t", files_id[x]);
            }
        }
        printf("\n");
    }

    return 0;
}

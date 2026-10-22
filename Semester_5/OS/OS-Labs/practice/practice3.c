#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr = fopen("test.txt", "w");

    if (fptr == NULL)
    {
        printf("Error opening file for writing!\n");
        return 1;
    }
    printf("Writing data to test.txt...\n");
    fprintf(fptr, "Hello Hussain! Welcome to File Handling.\n");
    fclose(fptr);

    fptr = fopen("test.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening file for reading!\n");
        return 1;
    }

    int roll;
    char name[50];
    printf("Reading data back from test.txt:\n\n");

    // fscanf() { reads input separated by whitespace (spaces, tabs, or newlines) }
    // %49s: Max 49 chars, stop on ' - ', and then reads int roll
    // while (fscanf(fp, " %49[^- ] - %d", name, &roll) == 2) {
    //	printf("Name: [%s] | Roll No: %d\n", name, roll);
    // }
    
    // fgets() {  reads a full line of text (including spaces and punctuation) 
    // up to the buffer size limit or until it encounters a newline character (\n) }
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        if (sscanf(buffer, "%49s - %d", name, &roll) == 2) {
            printf("Name: [%s] | Roll No: %d\n", name, roll);
        }
    }

    fclose(fptr);

    printf("\nFile handling completed successfully.\n");
    return 0;
}

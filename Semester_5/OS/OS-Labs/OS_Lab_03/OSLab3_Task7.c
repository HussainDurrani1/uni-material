#include <stdio.h>

int string_compare(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

int main() {
    char id[100][20];
    char title[100][50];
    char author[100][50];
    char category[100][30];
    int edition[100];
    int price[100];
    int count = 0;

    FILE *file = fopen("task7.txt", "r");
    if (file != NULL) {
        while (count < 100 && fscanf(file, "%s %s %s %s %d %d", 
               id[count], title[count], author[count], category[count], &edition[count], &price[count]) == 6) {
            count++;
        }
        fclose(file);
    }

    int choice;
    do {
        printf("\n==================== MENU ====================\n");
        printf("1. Add a record\n");
        printf("2. Search a record by ID\n");
        printf("3. Show all records\n");
        printf("4. Show books with price greater than a given limit (1000)\n");
        printf("5. Save and exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1: {
                if (count >= 100) {
                    printf("Library is full.\n");
                    break;
                }
                printf("Enter ID, Title, Author, Category, Edition, Price:\n");
                if (scanf("%s %s %s %s %d %d", 
                    id[count], title[count], author[count], category[count], &edition[count], &price[count]) == 6) {
                    count++;
                    printf("Record added successfully.\n");
                } else {
                    printf("Error reading input.\n");
                }
                break;
            }
            case 2: {
                char search_id[20];
                printf("Enter Book ID to search: ");
                scanf("%s", search_id);
                int found = 0;
                for (int i = 0; i < count; i++) {
                    if (string_compare(id[i], search_id) == 0) {
                        printf("\nFound:\n");
                        printf("%s %s %s %s %d %d\n", id[i], title[i], author[i], category[i], edition[i], price[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Book not found.\n");
                }
                break;
            }
            case 3: {
                printf("\n--- All Book Records (%d) ---\n", count);
                for (int i = 0; i < count; i++) {
                    printf("%s %s %s %s %d %d\n", id[i], title[i], author[i], category[i], edition[i], price[i]);
                }
                break;
            }
            case 4: {
                int limit = 1000;
                printf("\n--- Books with Price > %d ---\n", limit);
                int match = 0;
                for (int i = 0; i < count; i++) {
                    if (price[i] > limit) {
                        printf("%s %s %s %s %d %d\n", id[i], title[i], author[i], category[i], edition[i], price[i]);
                        match = 1;
                    }
                }
                if (!match) {
                    printf("No books found.\n");
                }
                break;
            }
            case 5: {
                file = fopen("task7.txt", "w");
                if (file == NULL) {
                    printf("Error opening file!\n");
                    break;
                }
                for (int i = 0; i < count; i++) {
                    fprintf(file, "%s %s %s %s %d %d\n", id[i], title[i], author[i], category[i], edition[i], price[i]);
                }
                fclose(file);
                printf("Saved to task7.txt. Exiting...\n");
                break;
            }
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
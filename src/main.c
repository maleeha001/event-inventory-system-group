#include <stdio.h>
#include "headers.h"

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== EVENT INVENTORY SYSTEM =====\n");
        printf("1. Item Management\n");
        printf("2. Vendor Management\n");
        printf("3. Stock Management\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            itemmenu();
            break;
        case 2:
            vendormenu();
            break;
        case 3:
            stockmenu();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}

/* ===== MAIN FUNCTION ===== */
int main()
{
    loadData(); // load saved data from files
    title();
    mainmenu();
    return 0;
}
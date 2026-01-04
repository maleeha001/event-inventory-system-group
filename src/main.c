#include "headers.h"

/* ===== TITLE ===== */
void title()
{
    printf("********************************************\n");
    printf("WELCOME TO EVENT INVENTORY MANAGEMENT SYSTEM\n");
    printf("********************************************\n");
}

/* ===== MAIN MENU ===== */
void mainmenu()
{
    int choice;
    while (1)
    {
        printf("\n1. Event Items Inventory\n");
        printf("2. Vendor Management\n");
        printf("3. Stock In (Purchase)\n");
        printf("4. Stock Out (Event Usage)\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
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
            stockinmenu();
            break;
        case 4:
            stockoutmenu();
            break;
        case 5:
            printf("Exiting Program...\n");
            return;
        default:
            printf("Invalid Choice\n");
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
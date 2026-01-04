#include <stdio.h>
#include <string.h>
#include "headers.h"

/* ================= DATE STRUCT ================= */
struct date

{
    int day;
    int month;
    int year;
};

/* ================= ITEM STRUCT ================= */
struct item
{
    int itemid;
    char itemname[50];
    int quantity;
};

struct item itemcollection[100];
int itemcount = 0;
static FILE *fp;

FILE *fp;

/* ================= FILE FUNCTIONS ================= */

// Load items from file
void loadFromFile()
{
    fp = fopen("items.dat", "rb");
    if (fp != NULL)
    {
        fread(&itemcount, sizeof(int), 1, fp);
        fread(itemcollection, sizeof(struct item), itemcount, fp);
        fclose(fp);
    }
}

// Save items to file
void saveToFile()
{
    fp = fopen("items.dat", "wb");
    if (fp != NULL)
    {
        fwrite(&itemcount, sizeof(int), 1, fp);
        fwrite(itemcollection, sizeof(struct item), itemcount, fp);
        fclose(fp);
    }
}

/* ---------- ITEM MENU ---------- */

void itemmenu()
{
    loadFromFile();
    int choice;

    while (1)
    {
        printf("\n--- ITEM MENU ---\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter Item ID: ");
            scanf("%d", &itemcollection[itemcount].itemid);

            printf("Enter Item Name: ");
            scanf("%s", itemcollection[itemcount].itemname);

            printf("Enter Quantity: ");
            scanf("%d", &itemcollection[itemcount].quantity);

            itemcount++;
            saveToFile();
        }
        else if (choice == 2)
        {
            if (itemcount == 0)
            {
                printf("No items available.\n");
            }
            for (int i = 0; i < itemcount; i++)
            {
                printf("\nID: %d\nName: %s\nQty: %d\n",
                       itemcollection[i].itemid,
                       itemcollection[i].itemname,
                       itemcollection[i].quantity);
            }
        }
        else if (choice == 3) // Search Item
        {
            int id, found = 0;
            printf("Enter Item ID: ");
            scanf("%d", &id);

            for (int i = 0; i < itemcount; i++)
            {
                if (itemcollection[i].itemid == id)
                {
                    found = 1;
                    printf("\nItem ID: %d\nName: %s\nQuantity: %d\n",
                           itemcollection[i].itemid,
                           itemcollection[i].itemname,
                           itemcollection[i].quantity);
                    break;
                }
            }
            if (!found)
                printf("Item Not Found!\n");
        }
        else if (choice == 4) // Delete Item
        {
            int id, found = 0;
            printf("Enter Item ID to Delete: ");
            scanf("%d", &id);

            for (int i = 0; i < itemcount; i++)
            {
                if (itemcollection[i].itemid == id)
                {
                    found = 1;
                    for (int j = i; j < itemcount - 1; j++)
                    {
                        itemcollection[j] = itemcollection[j + 1];
                    }
                    itemcount--;
                    saveToFile(); // save after delete
                    printf("Item Deleted Successfully!\n");
                    break;
                }
            }
            if (!found)
                printf("Item Not Found!\n");
        }
        else if (choice == 5)
        {
            break;
        }
        else
            printf("Invalid choice!\n");
    }
}

/* ================= MAIN FUNCTION ================= */

int main()
{
    loadFromFile(); // load items at program start
    itemmenu();
    return 0;
}
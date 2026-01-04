#include <stdio.h>
#include <string.h>
#include "headers.h"

struct stock
{
    int itemid;
    char itemname[50];
    int quantity;
};

void loadStock();
void saveStock();
void stockmenu();

int main()
{
    stockmenu();
    return 0;
}

/* ================= STOCK ================= */

struct stock stockcollection[100];
int stockcount = 0;

/* ---------- FILE FUNCTIONS ---------- */

void loadStock()
{
    FILE *fp = fopen("stock.dat", "rb");
    if (fp != NULL)
    {
        fread(&stockcount, sizeof(int), 1, fp);
        fread(stockcollection, sizeof(struct stock), stockcount, fp);
        fclose(fp);
    }
}

void saveStock()
{
    FILE *fp = fopen("stock.dat", "wb");
    if (fp != NULL)
    {
        fwrite(&stockcount, sizeof(int), 1, fp);
        fwrite(stockcollection, sizeof(struct stock), stockcount, fp);
        fclose(fp);
    }
}

/* ---------- STOCK MENU ---------- */

void stockmenu()
{
    loadStock();

    while (1)
    {
        int choice;
        printf("\n1.Stock In\n");
        printf("2.Stock Out\n");
        printf("3.Display Stock\n");
        printf("4.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 1) /* STOCK IN */
        {
            int id, qty, found = 0;

            printf("Enter Item ID: ");
            scanf("%d", &id);

            for (int i = 0; i < stockcount; i++)
            {
                if (stockcollection[i].itemid == id)
                {
                    printf("Enter Quantity to Add: ");
                    scanf("%d", &qty);

                    stockcollection[i].quantity += qty;
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                stockcollection[stockcount].itemid = id;

                printf("Enter Item Name: ");
                scanf("%s", stockcollection[stockcount].itemname);

                printf("Enter Quantity: ");
                scanf("%d", &stockcollection[stockcount].quantity);

                stockcount++;
            }

            saveStock();
            printf("Stock updated successfully.\n");
        }

        else if (choice == 2) /* STOCK OUT */
        {
            int id, qty, found = 0;

            printf("Enter Item ID: ");
            scanf("%d", &id);

            for (int i = 0; i < stockcount; i++)
            {
                if (stockcollection[i].itemid == id)
                {
                    printf("Enter Quantity to Remove: ");
                    scanf("%d", &qty);

                    if (stockcollection[i].quantity >= qty)
                    {
                        stockcollection[i].quantity -= qty;
                        printf("Stock removed successfully.\n");
                    }
                    else
                    {
                        printf("Not enough stock!\n");
                    }
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Item not found!\n");

            saveStock();
        }

        else if (choice == 3) /* DISPLAY */
        {
            for (int i = 0; i < stockcount; i++)
            {
                printf("\nItem ID: %d\nName: %s\nQuantity: %d\n",
                       stockcollection[i].itemid,
                       stockcollection[i].itemname,
                       stockcollection[i].quantity);
            }
        }

        else if (choice == 4)
            break;

        else
            printf("Invalid Choice\n");
    }
}
#include <stdio.h>
#include <stdio.h>
/* ================= VENDOR ================= */

struct vendor // represents suppliers of inventory items
{
    int vendorid;
    char name[50];
    char contact[20];
};

struct vendor vendorcollection[100];
int vendorcount = 0;

/* ---------- FILE FUNCTIONS ---------- */

void loadVendors()
{
    FILE *fp = fopen("vendors.dat", "rb");
    if (fp != NULL)
    {
        fread(&vendorcount, sizeof(int), 1, fp);
        fread(vendorcollection, sizeof(struct vendor), vendorcount, fp);
        fclose(fp);
    }
}

void saveVendors()
{
    FILE *fp = fopen("vendors.dat", "wb");
    if (fp != NULL)
    {
        fwrite(&vendorcount, sizeof(int), 1, fp);
        fwrite(vendorcollection, sizeof(struct vendor), vendorcount, fp);
        fclose(fp);
    }
}

/* ---------- VENDOR MENU ---------- */

void vendormenu()
{
    loadVendors(); // Load data from file at start

    while (1)
    {
        int choice;
        printf("\n1.Add Vendor\n");
        printf("2.Display Vendors\n");
        printf("3.Search Vendor\n");
        printf("4.Delete Vendor\n");
        printf("5.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter Vendor ID: ");
            scanf("%d", &vendorcollection[vendorcount].vendorid);

            printf("Enter Vendor Name: ");
            scanf("%s", vendorcollection[vendorcount].name);

            printf("Enter Contact: ");
            scanf("%s", vendorcollection[vendorcount].contact);

            vendorcount++;
            saveVendors(); // Save after add
        }
        else if (choice == 2)
        {
            for (int i = 0; i < vendorcount; i++)
            {
                printf("\nVendor ID:%d\nName:%s\nContact:%s\n",
                       vendorcollection[i].vendorid,
                       vendorcollection[i].name,
                       vendorcollection[i].contact);
            }
        }
        else if (choice == 3)
        {
            int id, found = 0;
            printf("Enter Vendor ID: ");
            scanf("%d", &id);

            for (int i = 0; i < vendorcount; i++)
            {
                if (id == vendorcollection[i].vendorid)
                {
                    printf("\nVendor ID:%d\nName:%s\nContact:%s\n",
                           vendorcollection[i].vendorid,
                           vendorcollection[i].name,
                           vendorcollection[i].contact);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Vendor not found!\n");
        }
        else if (choice == 4)
        {
            int id;
            printf("Enter Vendor ID to Delete: ");
            scanf("%d", &id);

            for (int i = 0; i < vendorcount; i++)
            {
                if (id == vendorcollection[i].vendorid)
                {
                    for (int j = i; j < vendorcount - 1; j++)
                        vendorcollection[j] = vendorcollection[j + 1];

                    vendorcount--;
                    saveVendors(); // Save after delete
                    printf("Vendor deleted successfully.\n");
                    break;
                }
            }
        }
        else if (choice == 5)
            break;
        else
            printf("Invalid Input\n");
    }
}
int main()
{
    vendormenu();
    return 0;
}

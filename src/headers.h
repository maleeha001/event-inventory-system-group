#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <string.h>

/* ===== STRUCTS ===== */

struct date
{
    int day;
    int month;
    int year;
};

struct item
{
    int itemid;
    char itemname[50];
    int quantity;
};

struct vendor
{
    int vendorid;
    char name[50];
    char contact[20];
};

struct stockin
{
    int stockid;
    int vendorid;
    int itemid;
    int quantity;
};

struct stockout
{
    int usageid;
    int itemid;
    int quantity;
};

/* ===== FUNCTION DECLARATIONS ===== */

void itemmenu();
void vendormenu();
void stockinmenu();
void stockoutmenu();

void loadData();

#endif

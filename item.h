#ifndef ITEM_H
#define ITEM_H

struct _Item
{
double price;
char *sku;
char *name;
char *category;
char *description;
};

typedef struct _Item Item;

#endif

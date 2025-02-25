#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "item.h" // ITEM_H

void add_item(Item *item_list, double price, char *sku, char *category,char *name, int index);
void free_items(Item *item_list, int size);
double average_price(Item *item_list, int size);
void print_items(Item *item_list, int size);

int main(int argc, char *argv[]) {
	const int size = 5;
	Item *item_list = (Item *)malloc(size *sizeof(Item));

	add_item(item_list, 5.00, "19282","breakfast", "reese's cereal", 0);
	add_item(item_list, 3.25, "79862", "dairy", "milk", 1);
	add_item(item_list, 1.10, "34575", "fruit", "apple", 2);
	add_item(item_list, 2.00, "23283", "produce", "cilantro", 3);
	add_item(item_list, 3.50, "29485", "candy", "snickers", 4);
	
	print_items(item_list, size);

	// calculate and print average price
	printf("Average Price: %.3f\n", average_price(item_list, size));

	// search for sku if provided
	if (argc == 2) {
		char *search_sku = argv[1];
		int ct = 0;
		while (ct < size && strcmp(item_list[ct].sku, search_sku) != 0) {
			ct++;
			}

			if (ct < size) {
				printf("Item found:\n");
				printf("---------------\n");
				printf("Item Name: %s\n", item_list[ct].name);
				printf("Item SKU: %s\n", item_list[ct].sku);
				printf("Item Category: %s\n", item_list[ct].category);
				printf("Item Price = %.4f\n", item_list[ct].price);
			} else {
				printf("Item not found.\n");
			}
		}

		free_items(item_list, size);


		return 0;
}

// function to add an item to the list
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {
	item_list[index].price = price;
	item_list[index].sku - strdup(sku);
	item_list[index].category = strdup(category);
	item_list[index].name = strdup(name);
	item_list[index].description = strdup("");
	}

// function to print all items
void print_items(Item *item_list, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("################\n");
		printf("Item Name: %s\n", item_list[i].name);
		printf("Item SKU: %s\n", item_list[i].sku);
		printf("Item Category: %s\n", item_list[i].category);
		printf("Item Price: %.4f\n", item_list[i].price);
		printf("################\n");
	}
}

// function to calulcate average price
double average_price(Item *item_list, int size) {
	double sum = 0.0;
	int i;
	for (i = 0; i < size; i++) {
		sum += item_list[i].price;
	}
	return sum / size;
}

// function to free dynamically allcoated memory for all items
void free_items(Item *item_list, int size) {
	int i;
	for (i = 0; i < size; i++) {
		free(item_list[i].sku);
		free(item_list[i].name);
		free(item_list[i].category);
		free(item_list[i].description);
	}
	free(item_list); // free array itse;f
}

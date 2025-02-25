#include <iostream>
#include <string.h>
#include "item.h" // ITEM_H

void add_item(Item *item_list, double price, const std::string &sku, const std::string &category, const std::string &name, int index);
void free_items(Item *item_list);
double average_price(Item *item_list, int size);
void print_items(Item *item_list, int size);

int main(int argc, char *argv[]) {
	const int size = 5;
	Item *item_list = new Item[size]; 

	add_item(item_list, 5.00, "19282","breakfast", "reese's cereal", 0);
	add_item(item_list, 3.25, "79862", "dairy", "milk", 1);
	add_item(item_list, 1.10, "34575", "fruit", "apple", 2);
	add_item(item_list, 2.00, "23283", "produce", "cilantro", 3);
	add_item(item_list, 3.50, "29485", "candy", "snickers", 4);
	
	print_items(item_list, size);

	// calculate and print average price
	std::cout << "Average Price: " << average_price(item_list, size) << std::endl;

	// search for sku if provided
	if (argc == 2) {
		std::string search_sku = argv[1];
		int ct = 0;
		while (ct < size && item_list[ct].sku != search_sku) {
			ct++;
			}

			if (ct < size) {
				std::cout << "Item found:\n";
				std::cout << "---------------\n";
				std::cout << "Item Name: " << item_list[ct].name << std::endl;
				std::cout << "Item SKU: " << item_list[ct].sku << std::endl;
				std::cout << "Item Category: " << item_list[ct].category << std::endl;
				std::cout << "Item Price = " << item_list[ct].price << std::endl;
			} else {
				std::cout << "Item not found.\n" << std::endl;
			}
		}

		free_items(item_list);
		return 0;
}

// function to add an item to the list
void add_item(Item *item_list, double price, const std::string &sku, const std::string &category, const std::string &name, int index) {
	item_list[index].price = price;
	item_list[index].sku = sku;
	item_list[index].category = category;
	item_list[index].name = name;
}

// function to print all items
void print_items(Item *item_list, int size) {
	int i;
	for (i = 0; i < size; i++) {
		 std::cout << "###############" << std::endl;
		 std::cout << "item name = " << item_list[i].name << std::endl;
		 std::cout << "item sku = " << item_list[i].sku << std::endl;
		 std::cout << "item category = " << item_list[i].category << std::endl;						        
		 std::cout << "item price = " << item_list[i].price << std::endl;
		 std::cout << "###############" << std::endl;
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
void free_items(Item *item_list) {
	delete[] item_list; // free array itself
}

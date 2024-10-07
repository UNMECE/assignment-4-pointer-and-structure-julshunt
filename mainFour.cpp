// Name: Julian Hunter
// Class: C++ Intermediate Programming & Problem Solving
// Assignment:4 (Pointers & Structs)
// FileName: "mainFour.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"


// Function Declarations
void addItem(Item *item_list, double price, const char *sku, const char *category, const char *name, int index);
void printItems(Item *item_list, int structAmount);
double averagePrice(Item *item_list, int structAmount);
void freeMemory(Item *item_list, int size);

int main() {
    // Allocate memory for the array
    int structAmount = 5;
    Item *item_list = (Item *)malloc(sizeof(Item) * structAmount);
    if (item_list == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Add five items
    addItem(item_list, 24.99, "80000002387", "Media", "Sealed DVD", 0);
    addItem(item_list, 39.99, "SKU123", "Clothing", "Vintage Hat", 1);
    addItem(item_list, 49.99, "8007004062", "Media", "Quickbooks Software", 2);
    addItem(item_list, 59.99, "SKU101", "Electronics", "Honeywell Thermostat", 3);
    addItem(item_list, 79.99, "90909091", "Electronics", "VHS Player", 4);
    
    printItems(item_list, structAmount);
    
    double avgPrice = averagePrice(item_list, structAmount);
    printf("Average Price: $%.2f\n", avgPrice);
    
    freeMemory(item_list, structAmount);
    

    return 0;
}

void addItem(Item *item_list, double price, const char *sku, const char *category, const char *name, int index) {
    item_list[index].price = price;

    // Allocate memory for strings
    item_list[index].sku = (char*)malloc(strlen(sku) + 1);
    item_list[index].category = (char*)malloc(strlen(category) + 1);
    item_list[index].name = (char*)malloc(strlen(name) + 1);

    // Check for memory allocation failures
    if (item_list[index].sku == NULL || item_list[index].category == NULL || item_list[index].name == NULL) {
        fprintf(stderr, "Memory allocation failed for item strings\n");
        exit(1); // Exit on memory allocation failure
    }

    // Copy strings
    strcpy(item_list[index].sku, sku);
    strcpy(item_list[index].category, category);
    strcpy(item_list[index].name, name);
}

void printItems(Item *item_list, int structAmount) {

    for (int i = 0; i < structAmount; i++) {
        printf("Item %d: %s, %s, %s, $%.2f\n", i, item_list[i].sku, item_list[i].category, item_list[i].name, item_list[i].price);
    }
}

double averagePrice(Item *item_list, int structAmount) {
    double total = 0.00;
    for (int i = 0; i < structAmount; i++) {
        total += item_list[i].price;
    }
    return total / structAmount ; 
}

void freeMemory(Item *item_list, int structAmount) {
    // Free allocated memory
    for (int i = 0; i < structAmount; i++) {
        free(item_list[i].sku);
        free(item_list[i].category);
        free(item_list[i].name);
    
    free(item_list);
}
}
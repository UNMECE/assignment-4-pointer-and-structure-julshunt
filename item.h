// Name: Julian Hunter
// Class: C++ Intermediate Programming & Problem Solving
// Assignment:4 (Pointers & Structs)
// Purpose: 
// FileName: "item.h"

#include <stdio.h>

struct _Item
{
  double price;
  char *sku;
  char *name;
  char *category;
};
typedef struct _Item Item;
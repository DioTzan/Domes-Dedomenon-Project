#ifndef DD1_H
#define DD1_H

#include <stdio.h>

#define NAME_LEN 128
#define MAX_PRODUCTS 200
#define EAN_LEN 32

typedef struct product {
    int productCode;    // product identifier
    char productName[NAME_LEN];     // product name
    char ean[EAN_LEN];      // EAN / string code
    int productVariable;    // variable/stock or other metadata
    int productPrice;       // price (integer for demo)
} product;

//storage for products
extern product products[MAX_PRODUCTS];
extern int product_count;


//Menu displayed to the user — returns a choice 1..5 
int Menu(void);

//Parse a textual command (unused in the current demo)
void parse(char *input);

//Function declarations for menu operations
void addProduct(void);
void addOrder(void);
void printStock(void);
void makeOrder(void);

/* utility functions used by addProduct */
int find_product_by_ean(const char *ean);
int validate_ean(const char *ean);
void suggest_codes(const char *prefix);

#endif

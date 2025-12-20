#ifndef DD1_H
#define DD1_H

#include <stdio.h>

#define NAME_LEN 128
#define MAX_PRODUCTS 200
#define EAN_LEN 32

#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"
#define BOLD    "\x1b[1m"


typedef struct orderProducts {
    long int productCode1;
    int quantify;                 
    int first;
    struct orderProducts *next;
} orderProducts;

typedef struct order {
    int clientCode;    // product identifier
    char businessName[NAME_LEN];     // Business name
    orderProducts *productList;
} order;

typedef struct orderFIFO {
    order* prev;
    order data;
    order* next;
} orderFIFO;

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
order addOrder(void);
void printStock(void);
void makeOrder(orderFIFO* head);

// utility functions used by addOrder
void print(order newOrder);
void sort_list(orderProducts *head);
orderProducts* newProduct(orderProducts *head);
orderFIFO* createFIFO(order data);
orderFIFO* addOrderToFIFO(orderFIFO *head, orderFIFO *tail, order data);
order removeOrderFromFIFO(orderFIFO *head,orderFIFO *tail);


// utility functions used by addProduct
int find_product_by_ean(const char *ean);
int validate_ean(const char *ean);
void suggest_codes(const char *prefix);

#endif

#include <string.h>
#include "dd1.h"

extern int product_count;

//Επιστρέφει τον δείκτη του προϊόντος με το δοσμένο EAN, ή -1 αν δεν βρεθεί
int find_product_by_ean(const char *ean) {
    for (int i = 0; i < product_count; ++i) {
        if (strcmp(products[i].ean, ean) == 0) return i;
    }
    return -1;
}
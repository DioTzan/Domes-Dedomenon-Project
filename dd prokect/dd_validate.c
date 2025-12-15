#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dd1.h"

// Επιστρέφει 1 αν το EAN είναι έγκυρο (13 ψηφία), 2 αν το μέγεθος είναι μεταξύ 4 και 12, αλλιώς 0
int validate_ean(const char *ean) {
    size_t len = strlen(ean);
    if (len == 13) {
        for (size_t i = 0; i < len; ++i) if (!isdigit((unsigned char)ean[i])) return 0;
        return 1;
    }
    if (len >= 4 && len < 13) return 2;
    return 0;
}

// Εμφανίζει προϊόντα που έχουν EAN (ή productCode string) με το ίδιο πρόθεμα
extern int product_count;

void suggest_codes(const char *prefix) {
    size_t plen = strlen(prefix);
    printf("Πιθανα αποτελεσματα που ξεκιανε με '%s':\n", prefix);
    int found = 0;
    for (int i = 0; i < product_count; ++i) {
        if (strncmp(products[i].ean, prefix, plen) == 0) {
            printf("  [%d] %s  (EAN: %s)\n", i, products[i].productName, products[i].ean);
            found = 1;
        }
    }
    if (!found) {
        printf("  (Δεν βρέθηκαν αποτελέσματα)\n");
    }
}
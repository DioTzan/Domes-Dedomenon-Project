#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dd1.h"

static void trim_newline(char *s) {
    size_t l = strlen(s);
    if (l > 0 && s[l-1] == '\n') s[l-1] = '\0';
}

static void to_lower(const char *src, char *dst, size_t n) {
    size_t i;
    for (i = 0; i + 1 < n && src[i] != '\0'; ++i) dst[i] = (char)tolower((unsigned char)src[i]);
    dst[i] = '\0';
}

void printStock(void) {
    char query[NAME_LEN + EAN_LEN + 4];
    printf("Δωσε κωδικο ή ονομα ('*' εκτυπονη τα παντα :) ): ");
    if (fgets(query, sizeof(query), stdin) == NULL) return;
    trim_newline(query);
    if (strcmp(query, "*") == 0) {
        printf("--Γεματοι απο αποθεμα Μπροκολοκο  --\n");
        for (int i = 0; i < product_count; ++i) {
            printf("%d: %s | EAN:%s | Price:%f | Stock:%d\n",
                   i, products[i].productName, products[i].ean,
                   products[i].productPrice, products[i].productVariable);
        }
        if (product_count == 0) printf("Επτωχευσαμεν Μπρουλι (δεν εχει stock)\n");
        return;
    }

    /* prepare lowercase query for name search */
    char qlow[sizeof(query)];
    to_lower(query, qlow, sizeof(qlow));
    int found = 0;
    size_t qlen = strlen(query);

    for (int i = 0; i < product_count; ++i) {
        /* exact EAN match */
        if (strcmp(products[i].ean, query) == 0) {
            printf("%d: %s | EAN:%s | Price:%f | Stock:%d\n",
                   i, products[i].productName, products[i].ean,
                   products[i].productPrice, products[i].productVariable);
            found = 1;
            continue;
        }
        /* EAN prefix match */
        if (qlen > 0 && strncmp(products[i].ean, query, qlen) == 0) {
            printf("%d: %s | EAN:%s | Price:%f | Stock:%d\n",
                   i, products[i].productName, products[i].ean,
                   products[i].productPrice, products[i].productVariable);
            found = 1;
            continue;
        }
        /* name substring match (case-insensitive) */
        char name_low[NAME_LEN];
        to_lower(products[i].productName, name_low, sizeof(name_low));
        if (strstr(name_low, qlow) != NULL) {
            printf("%d: %s | EAN:%s | Price:%f | Stock:%d\n",
                   i, products[i].productName, products[i].ean,
                   products[i].productPrice, products[i].productVariable);
            found = 1;
        }
    }
    if (!found) printf("Δεν εχουμε τετοια πρωιοντα '%s'.\n", query);
}

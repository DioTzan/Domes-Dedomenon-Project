#include <stdio.h>
#include <string.h>
#include "dd1.h"

extern int product_count;

static void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

//Προσθέτει ή ενημερώνει ένα προϊόν στη βάση δεδομένων (ανα Ean)
void addProduct(void) {
    char ean[EAN_LEN];
    product NewProduct;

    printf("--- Add / Ενημερωση πρωιντος---\n");
    printf("bro Δωσε ean :");
    if (fgets(ean, sizeof(ean), stdin) == NULL) return;
    trim_newline(ean);

    int v = validate_ean(ean);
    if (v == 0) {
        printf("Λαθος Ean.\n");
        return;
    }

    if (v == 2) {
        printf("Το Ean ειναι μικρο. Προτεινομενα προϊοντα:\n");
        suggest_codes(ean);
        printf("Βρεθηκε παρομοιος κωδικας ->\n");
        suggest_codes(ean);
        printf("Βαλε ολοκληρωμενο Ean (πατα enter για ακυρωση):\n");
        char choice[EAN_LEN];
        if (fgets(choice, sizeof(choice), stdin) == NULL) return;
        trim_newline(choice);
        if (strlen(choice) == 0) {
            printf("Ακυρωση προσθηκης προϊοντος.\n");
            return;
        }
        strncpy(ean, choice, sizeof(ean) - 1);
        ean[sizeof(ean) - 1] = '\0';
        if (validate_ean(ean) != 1) {
            printf("Λαθος Ean.\n");
            return;
        }
    }

    int existing_index = find_product_by_ean(ean);
    if (existing_index >= 0) {
        // Υπάρχει ήδη προϊόν -> ενημέρωση αποθέματος
        printf("Το προιον υπαρχει ηδη: %s (Ean=%s). Διαθεσιμο αποθεμα: %d.\n",
               products[existing_index].productName,
               products[existing_index].ean,
               products[existing_index].productVariable);

        printf("Βαλε ποσοτητα για προσθηκη: ");
        int add_quantity = 0;
        if (scanf("%d", &add_quantity) != 1) {
            printf("Λαθος ποσοτητα.\n");
            while ((getchar()) != '\n');
            return;
        }
        while ((getchar()) != '\n');
        if (add_quantity <= 0) {
            printf("Η ποσοτητα πρεπει να ειναι θετικη.\n");
            return;
        }
        products[existing_index].productVariable += add_quantity;
        printf("Νεο αποθεμα: %d\n", products[existing_index].productVariable);
        return;
    }

    // Νέο προϊόν
    strncpy(NewProduct.ean, ean, sizeof(NewProduct.ean) - 1);
    NewProduct.ean[sizeof(NewProduct.ean) - 1] = '\0';

    printf("Δωσε ονομα προϊοντος: ");
    if (fgets(NewProduct.productName, sizeof(NewProduct.productName), stdin) == NULL) {
        NewProduct.productName[0] = '\0';
    }
    trim_newline(NewProduct.productName);

    printf("Δωσε τιμη προϊοντος: ");
    if (scanf("%d", &NewProduct.productPrice) != 1 || NewProduct.productPrice < 0) {
        while ((getchar()) != '\n');
        printf("Λαθος τιμη.\n");
        return;
    }
    while ((getchar()) != '\n');

    printf("Δωσε ποσοτητα προϊοντος: ");
    if (scanf("%d", &NewProduct.productVariable) != 1 || NewProduct.productVariable < 0) {
        while ((getchar()) != '\n');
        printf("Λαθος ποσοτητα.\n");
        return;
    }
    while ((getchar()) != '\n');

    if (product_count < MAX_PRODUCTS) {
        products[product_count++] = NewProduct;
        printf("προιον προσθεθηκε: %s (Ean=%s). Διαθεσιμο αποθεμα: %d.\n",
               NewProduct.productName, NewProduct.ean, NewProduct.productVariable);
    } else {
        printf("Η βαση δεδομενων ειναι γεματη. Αδυνατη η προσθηκη νεου προϊοντος.\n");
    }
}
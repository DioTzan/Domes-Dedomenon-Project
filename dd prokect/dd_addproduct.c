#include <stdio.h>
#include <string.h>
#include "dd1.h"


static void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
// Προσθέτει ή ενημερώνει ένα προϊόν στη βάση δεδομένων (ανα Ean)
void addorder(){
    char ean[EAN_LEN];
    product NewProduct;
    printf("--- Add / Update Product ---\n");
    printf("give us your ean :");
    if (fgets(ean, sizeof(ean), stdin) == NULL) {
        return;
    }
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
        if (fgets(choice, sizeof(choice), stdin) == NULL){
             return;
        }
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
        int existing_index = find_product_by_ean(ean);
        if(existing_index >= 0){
            printf("Το προιον υπαρχει ηδη: %s (Ean=%s). Διαθεσιμο αποθεμα: %d.\n", 
                    products[existing_index], products[existing_index].ean, 
                    products[existing_index].productVariable);
            printf("Βαλε ποσοτητα για προσθηκη: ");
            int add_quantity;
            if (scanf("%d", &add_quantity) != 1 || add_quantity <= 0) {
                printf("Λαθος ποσοτητα.\n");
                while((getchar()) != '\n'){
                    products[existing_index].productVariable += add_quantity;
                printf("Νεο αποθεμα: %d\n", products[existing_index].productVariable);
                return;
                }
            }
        //Νεο προιον
        strncpy(NewProduct.ean, ean, sizeof(NewProduct.ean) - 1);
        NewProduct.ean[sizeof(NewProduct.ean) - 1] = '\0';
        printf("Δωσε ονομα προϊοντος: "); 
        if (fgets(NewProduct.productName, sizeof(NewProduct.productName), stdin) == NULL) {
            NewProduct.productName[0] = '\0';
        }
        trim_newline(NewProduct.productName);
        printf("Δωσε τιμη προϊοντος: ");

    }
}
}
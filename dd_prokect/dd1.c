// Onomata Tzanatos Dionyses        Kwnstantinos Velissaris
// AM      2022202400203            2022202400021
// Mail    dit24203@go.uop.gr       dit24021@go.uop.gr

#include "dd1.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

int Menu(void);
void parse(char *input);

int main (void){

    orderFIFO *head=NULL, *tail=NULL;
    int option;
    option = Menu();
    printf("Please give a command\n");
    do{
        switch (option){
            case 1:
                addProduct();
                break;
            case 2:     
                tail = addOrderToFIFO(head,tail,addOrder());
                break;
            case 3:    
                printStock();
                break;
            case 4:
                if((head==NULL)&&(tail==NULL)){
                    printf("there are no order to execute");
                    break;
                }
                makeOrder(head,tail);
                break;
            case 5:     //exit
                printf("Exit\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
        option=Menu();
   }while (option != 5);

return 0;
}

int Menu(void) {
    printf("\n");
    printf(BOLD MAGENTA "┌─────────────────────────┐\n" RESET);
    printf(BOLD MAGENTA "│" RESET BOLD CYAN "           Ε Α Ν         " RESET BOLD MAGENTA "│\n" RESET);
    printf(BOLD MAGENTA "└─────────────────────────┘\n\n" RESET);
    printf(BOLD BLUE "Press 1" RESET BLUE "add product\n"RESET);
    printf(BOLD RED "Press 2" RESET RED "add order\n"RESET);
    printf(BOLD YELLOW "Press 3" RESET YELLOW "to print stock\n"RESET);
    printf(BOLD GREEN "Press 4" RESET GREEN "to make order\n"RESET);
    printf(BOLD CYAN "Press 5" RESET CYAN "to exit\n"RESET);
    int Start_Button;
    do {
        if (scanf("%d", &Start_Button) != 1) {
            // clear invalid input
            while ((getchar()) != '\n');
            Start_Button = 0;
        } else {
            while ((getchar()) != '\n'); // consume newline
        }
        if (Start_Button < 1 || Start_Button > 5) {
            printf("Please press either 1 or 2 or 3 or 4 or 5\n");
        }
    } while (Start_Button < 1 || Start_Button > 5);
    return Start_Button;
}

/*void addProduct(void){
    printf("Add Product\n");
    
}*/



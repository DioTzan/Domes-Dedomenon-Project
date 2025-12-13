// Onomata Tzanatos Dionyses        Kwnstantinos Velissaris
// AM      2022202400203            2022202400021
// Mail    dit24203@go.uop.gr       dit24021@go.uop.gr
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "dd1.h"

int Menu(void);
void parse(char *input);

int main (void){
    int option;
    option=Menu();
    printf("Please give a command\n");
    char user_input[100];
   do{
    switch (option){
        case 1:
            addProduct();
            break;
        case 2:     
            addOrder();
            break;
        case 3:    
            printStock();
            break;
        case 4:    
            makeOrder();
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

int Menu(void){
    jump_menu:
    printf("Press 1 add product\n");
    printf("Press 2 add order\n");
    printf("Press 3 to print stock\n");
    printf("Press 4 to make order\n");
    printf("Press 5 to exit\n");
    int Start_Button;
	do{	
		scanf("%d", &Start_Button);
        while((getchar()) != '\n');
		if(Start_Button != 1 && Start_Button != 2 && Start_Button != 3 && Start_Button != 4 && Start_Button != 5){
			printf("Please press either 1 or 2 or 3 or 4 or 5\n");
		}
    } while(Start_Button != 1 && Start_Button != 2 && Start_Button != 3 && Start_Button !=4 && Start_Button !=5);
    return Start_Button;
}

/*void addProduct(void){
    printf("Add Product\n");
    
}*/

void addOrder(void){
    printf("Add Order\n");
   
}

void printStock(void){
    printf("Print Stock\n");

}

void makeOrder(void){
    printf("Make Order\n");
}
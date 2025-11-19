// Onomata Tzanatos Dionyses        Kwnstantinos Velissaris
// AM      2022202400203            2022202400021
// Mail    dit24203@go.uop.gr       dit24021@go.uop.gr
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct order{
    int claientCode;
    char *bisnesName;
    int productCode;
    int varaiable;
    int first;
}order;

typedef struct product{
    int productCode;
    char *productName;
    int productCode;
    int productVaraiable;
    int productPrice;
}product;

int Menu(void);
void parse(char *input);

int main (void){
    int option;
    option=Menu();
    printf("Please give a command\n");
    char user_input[100];
    /*while(1){
        fgets(user_input, sizeof(user_input), stdin);
        parse(user_input);
    }*/
   do{
    switch (option){
        case 1:     //dio
            printf("Add Product\n");
            break;
        case 2:     //kvstas
            printf("Add Order\n");
            break;
        case 3:     //dio
            printf("Print Stock\n");
            break;
        case 4:     //kvsyas
            printf("Make Order\n");
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

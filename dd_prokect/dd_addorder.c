#include "dd1.h"

#include <stdlib.h>

#include <stdio.h>

void addOrder(void){
    order newOrder;
    //orderProducts

    printf("give us your clientCode :");
    scanf("%d",&newOrder.clientCode);
    while ((getchar()) != '\n');

    printf("give us your businessName :");
    scanf("%s",&newOrder.businessName);
    while ((getchar()) != '\n');
    
    newOrder.productList=NULL;
	int wantNewProduct=1;
	printf("now y'll chose your products\n");
    while(wantNewProduct){
		//adds the products in the list and create an new orderproduct struct
		newOrder.productList=newProduct(newOrder.productList);

		printf("do y want to add something else to your order;\nIf yes then type '1' else type '0' :");
        scanf("%d",&wantNewProduct);
        while ((getchar()) != '\n');
    }        	
	printf("thanks for the order, now its completed.\n");


    print(newOrder);

}

orderProducts* newProduct(orderProducts *head){

	orderProducts *new;
    new=(orderProducts *)malloc(sizeof(orderProducts));    
    if (new == NULL) 
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
	printf("give us productCode :");
	scanf("%d",&new->productCode1);
    while ((getchar()) != '\n');
	printf("give us your quantify :");
	scanf("%d",&new->quantify);
    while ((getchar()) != '\n');
	printf("give us your emergencyNumber for that order :");
	scanf("%d",&new->first);
    while ((getchar()) != '\n');
	
	

    new->next = head;
    head = new;
    
	return head;
}


void sort_list(orderProducts *head){
    if(head==NULL)
        return;
    int sorted,i,j,tempNum;
    char tempWord[45];
    do
    {
        sorted=0;
        orderProducts *current=head, *min_elem;
        while(current->next != NULL)
        {
            min_elem=current;
            if(current->first<current->next->first)
                min_elem=current->next;
            if(min_elem!=current)
            {
                tempNum=current->productCode1;
                current->productCode1=current->next->productCode1;
                current->next->productCode1=tempNum;
                tempNum=current->quantify;
                current->quantify=current->next->quantify;
                current->next->quantify=tempNum;
                tempNum=current->first;
                current->first=current->next->first;
                current->next->first=tempNum;
                sorted=1;
            }
            current=current->next;
        }
    }while(sorted);
}


void print(order newOrder){
    order* temp=&newOrder;
    printf("client code=%d\n",temp->clientCode);
    printf("business name=%s\n\n",temp->businessName);

	orderProducts *temp2=temp->productList;
    while (temp2 != NULL) {
        printf("product code=%d\n", temp2->productCode1);
        printf("quantify=%d\n", temp2->quantify);
        printf("first=%d\n", temp2->first);
        temp2 = temp2->next;
    }
}

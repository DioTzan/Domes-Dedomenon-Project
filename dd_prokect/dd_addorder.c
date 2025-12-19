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
    scanf("%s",newOrder.businessName);
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
    int flag=0;
    int i;
    int productCodeTemp;
    int quantifyTemp;                 
    int firstTemp;
	orderProducts *new;
    new=(orderProducts *)malloc(sizeof(orderProducts));    
    if (new == NULL) 
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
	printf("give us productCode :");
	scanf("%d",&productCodeTemp);
    while ((getchar()) != '\n');
    for(i=0;i<MAX_PRODUCTS;i++){
        if (products[i].productCode==productCodeTemp){
            flag=1;
            new->productCode1=productCodeTemp;
            break;
        }
    }
    if(flag==0){
        //den breuhke product
        printf("\nthere is no such of an product here\n");
        return head;
    }
	printf("\ngive us your quantify :");
	scanf("%d",&quantifyTemp);
    while ((getchar()) != '\n');
    if (products[i].productVariable>=quantifyTemp){
        flag=1;
        new->quantify=quantifyTemp;
    }
    if(flag==0){
        //den uparxeia apouema
        printf("\nther is not of that much of varaiable \n");
        return head;
    }
    do
    {    
        printf("give us your emergencyNumber for that order [1,10]:");
        scanf("%d",&firstTemp);
        while ((getchar()) != '\n');
    } while ((firstTemp<=0)&&(firstTemp>10));
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

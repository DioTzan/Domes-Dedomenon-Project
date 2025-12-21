#include<stdio.h>
#include"dd1.h"

void makeOrder(orderFIFO **head, orderFIFO **tail){
    order data;
    do
    {
        data=removeOrderFromFIFO(head,tail);        
        data=exePrint(data);
        printf("\n\n");
        freeProductList(data.productList);
    } while ((*head != NULL)&&(*tail!=NULL));

}

void freeProductList(orderProducts *head) {
    while (head != NULL) {
        orderProducts *temp = head;
        head = head->next;
        free(temp);
    }
}

order removeOrderFromFIFO(orderFIFO **head, orderFIFO **tail) {

    orderFIFO* temp = *head;
    order data = temp->data;
    
    if (*head == *tail) { // Only one element
        *head = NULL;
        *tail = NULL;
    } else {
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    }
    
    free(temp);
    return data;
}


void print(order Order){
    order* temp=&Order;
    printf("#----Client code=%d ----#\n",temp->clientCode);
    printf("#----Business name=%s ----#\n\n  --- PRODUCTS ---\n",temp->businessName);
    int i;
	orderProducts *temp2=temp->productList;
    while (temp2 != NULL) {
        /*printf("-Product code=%s\n", temp2->productCode1);
        printf("-Quantify=%d\n", temp2->quantify);
        printf("-First=%d\n", temp2->first);*/
        for(i=0;i<MAX_PRODUCTS;i++){
            if (strcmp(products[i].ean ,temp2->productCode1)==0){
                break;
            }
        }
        printf("\n- %s  (%d) * %lf  =  %lf \n",products[i].productName,temp2->quantify,products[i].productPrice,(products[i].productPrice*temp2->quantify));
        temp2 = temp2->next;
    }
}


order exePrint(order Order){
    order* temp=&Order;
    printf("#----Client code=%d ----#\n",temp->clientCode);
    printf("#----Business name=%s ----#\n\n  --- PRODUCTS ---\n",temp->businessName);
    int i;
	orderProducts *temp2=temp->productList;
    while (temp2 != NULL) {
        /*printf("-Product code=%s\n", temp2->productCode1);
        printf("-Quantify=%d\n", temp2->quantify);
        printf("-First=%d\n", temp2->first);*/
        for(i=0;i<MAX_PRODUCTS;i++){
            if (strcmp(products[i].ean ,temp2->productCode1)==0){
                break;
            }
        }
        if(products[i].productVariable>=temp2->quantify){
            products[i].productVariable-=temp2->quantify;
            printf("\n- %s  (%d) * %lf  =  %lf \n",products[i].productName,temp2->quantify,products[i].productPrice,(products[i].productPrice*temp2->quantify));
        }else{
            printf("\n--There is not enough stock for product %s. Available stock: %d, requested: %d but we are gonna give y what we have, all the Available stock\n",products[i].productName,products[i].productVariable,temp2->quantify);
            printf("- %s  (%d) * %lf  =  %lf \n",products[i].productName,products[i].productVariable,products[i].productPrice,(products[i].productPrice*products[i].productVariable));
            products[i].productVariable=0;
        }
        temp2 = temp2->next;
    }
    return *temp;
}
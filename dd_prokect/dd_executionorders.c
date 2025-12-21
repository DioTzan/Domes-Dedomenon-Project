#include<stdio.h>
#include"dd1.h"

void makeOrder(orderFIFO* head, orderFIFO *tail){
    printf("Excecute Order\n");
    order data;
    do
    {
        printf("got in to the delete while loop\n");
        data=removeOrderFromFIFO(head,tail);
        printf("after remuve funcrion\n");
        print(data);

    } while ((head != NULL)||(tail!=NULL));

}


order removeOrderFromFIFO(orderFIFO *head,orderFIFO *tail) {

    orderFIFO* temp = head;
    order data = temp->data;
    
    if (head == tail) { // Only one element
        tail = NULL;
        head = NULL;
    } else {
        head = head->next;
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
#include <stdio.h>
#include <dd1.h>

order addorder(){
    order newOrder;
    //orderProducts

    orderProducts head;
	head.productCode=0;
	head.quantify=0;
 	head.first=0;
    printf("give us your clientCode :");
    scanf("%d",&newOrder.clientCode);

    printf("give us your businessName :");
    scanf("%s",&newOrder.businessName);
    int wantNewProduct=1;
    while(wantNewProduct){

		printf("do y want to add something to your order;\nIf yes then type '1' else '0' :");
        scanf("%d",&wantNewProduct);
        if(wantNewProduct==1){
        	//addthe products in the list and create an new orderproduct struct
        	orderProducts new;
        	head.next=&new;
        	printf("give us productCode and when y ar finished type '-1' :");
			scanf("%d",&new.productCode);
	        printf("give us your quantify :");
	        scanf("%d",&new.quantify);
	        printf("give us your emergencyNumber for that order :");
	        scanf("%d",&new.first);
        }else{
        	print("thanks for the order, now its completed.");
        }
    }
	return new Order;
}
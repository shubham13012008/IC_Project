#include"train.h"
void grahakMenu(){
    int parth;
    while(1){
        printf("\n---- USER PORTAL ----");
        printf("\n1. Search Trains");
        printf("\n2. Book a Ticket (Using Train Number)");
        printf("\n3. Cancel a Ticket");
        printf("\n4. Back to Main Menu");
        printf("\nChoice: ");
        scanf("%d", &parth);  
        
        switch(parth) {
            case 1:
            // isko baad mein train add karne ke baad karenge
            break;

            case 2:
            printf("booking train");
            break;

            case 3:
            printf("Cancel Ticket");
            break;

            case 4:
            return;

            default:
            printf("\nInvalid selection");
        }
    }
}
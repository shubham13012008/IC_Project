#include"train.h"
void grahakMenu(){
    int parth;
    char s[50], d[50], dt[50];
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
            printf("Enter Source: ");
                scanf(" %[^\n]", s);

            printf("Enter Destination: "); 
                scanf(" %[^\n]", d);

            printf("Enter Date (DD/MM/YYYY): "); 
                scanf("%s", dt);

               
                break;
// isko baad mein train add karne ke baad karenge

            case 2:
            printf("booking train");
            break;

            case 3:
            printf("Cancel Ticket");
            break;

            case 4:
            return;

            default:
            printf("Invalid selection\n");
        }
    }
}
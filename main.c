#include "train.h"
int main(){
    int choice;
    while (1){
       
        printf("     IIT JODHPUR RAILWAY SYSTEM\n");
        printf("1. USER PORTAL (Search & Book)\n");
        printf("2. ADMIN PORTAL (Manage Trains)\n");
        printf("3. EXIT & SAVE\n");
        printf("Enter Choice(1,2 or 3): ");
        scanf("%d",&choice);
       switch (choice) {
            case 1:
                printf("admin");
                break;
            case 2:
                printf("user");
                break;
            case 3:
                printf("Exiting.\n");
                exit(0);
            default:
                printf("[Invalid Selection] Try again.\n");
        }

    }
    
   return 0; 

}
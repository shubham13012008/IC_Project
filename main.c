#include "train.h"
Train trains[MAX_TRAINS];
int trainCount = 0;
float totalPaise = 0.0;
int totalBooking = 0;
Booking bookings[MAX_BOOKING]; 
int bookingCount = 0;
int main(){
    int choice;
    loadFromFile();
    while (1){
       
        printf("     IIT JODHPUR RAILWAY SYSTEM\n");
        printf("1. USER PORTAL (Search & Book)\n");
        printf("2. ADMIN PORTAL (Manage Trains)\n");
        printf("3. EXIT & SAVE\n");
        printf("Enter Choice(1,2 or 3): ");
        scanf("%d",&choice);
       switch (choice) {
            case 1:
                grahakMenu();
                break;
            case 2:
                adminMenu();
                break;
            case 3:
                saveToFile();
                printf("Exiting.\n");
                exit(0);
            default:
                printf("[Invalid Selection] Try again.\n");
        }

    }
    
   return 0; 

}

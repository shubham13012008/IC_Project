#include "train.h"
#include <time.h>

int generatePNR() {
    srand(time(0));
    return rand() % 900000 + 100000; 
}
void bookTicket() {
    int train_num, lokesh;
    int found_train = 0; 
    printf("Train Booking Portal\n");
    printf("Enter Train No. for booking: \n");
    scanf("%d", &train_num);

    for (int i = 0; i < trainCount; i++) {
        if (trains[i].trainNo == train_num) {
            found_train = 1;
            
            printf("\nTrain Found: %s", trains[i].naam);
            printf("\n1. AC Class (Price %.2f)", trains[i].priceAC);
            printf("\n2. Sleeper Class (Price %.2f)", trains[i].priceSleeper);
            printf("\nChoose your seat type (1 or 2): ");
            scanf("%d", &lokesh);

        
            bookings[bookingCount].trainNo = train_num;
            bookings[bookingCount].pnr = generatePNR();
            bookings[bookingCount].status = 1;

            printf("Enter Passenger Name: ");
            getchar();
            fgets(bookings[bookingCount].passengerNaam,50, stdin);
            bookings[bookingCount].passengerNaam[strcspn(bookings[bookingCount].passengerNaam, "\n")] = 0;

            if (lokesh == 1) {
                if (trains[i].seatsAC > 0) {
                    strcpy(bookings[bookingCount].seatType, "AC");
                    
                
                    float base = trains[i].priceAC;
                    bookings[bookingCount].totalBill = base + (base * 0.12); 
                    
                    trains[i].seatsAC = trains[i].seatsAC - 1;
                    printf("Processing AC Ticket..\n");
               } else {
                    printf("Waitlist full No AC Ticket Left.\n");
                    return;
                }
            } 
            else if (lokesh == 2) {
                if (trains[i].seatsSleeper > 0) {
                    strcpy(bookings[bookingCount].seatType, "Sleeper");
                    
                    
                    bookings[bookingCount].totalBill = trains[i].priceSleeper * 1.03;
                    
                    trains[i].seatsSleeper = trains[i].seatsSleeper - 1;
                    printf("Processing Sleeper Ticket..\n");
                } else {
                    printf("Sorry, Sleeper is fully booked\n");
                    return;
                }
            } else {
                printf("Invalid Selection! Booking aborted.\n");
                return;
            }

        
            printf("Ticket Confirmed for %s\n", bookings[bookingCount].passengerNaam);
            printf("Final PNR: %d\n", bookings[bookingCount].pnr);
            printf("Amount Paid: INR %.2f\n", bookings[bookingCount].totalBill);
            
            bookingCount++; 
            return;
        }
    }

    if (found_train == 0) {
        printf("Error: Train Number %d is not in our records.\n", train_num);
    }
}
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
void cancelTicket() {
    int pnrInput;
    int ticketMili = 0;
    float refundAmount =0;
    float cancellationCharge =0;
    int bookingIndex = -1;
    int trainIndex = -1;

    printf("        TICKET CANCELLATION\n");

    //Yahan par ham user se PNR no. le rhe hain
    printf("Apna PNR number enter karein: \n");
    scanf("%d", &pnrInput);

    //Booking Checking basically PNR based
    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].pnr == pnrInput) {
            bookingIndex = i;
            ticketMili = 1;
            break;
        }
    }
    //let us suppose agar galat PNR daalde and booking na mile to
    if (ticketMili == 0) {
        printf("Is PNR par koi booking nahi mili hai.\n");
        printf("Kripya karke sahi PNR enter karein.\n");
        return;
    }

    //Ticket already cancelled to nhi uski checking
    if (bookings[bookingIndex].status == 0) {
        printf("\nSorry.\n");
        printf("Lekin yeh ticket pehle hi cancel ho chuki hai.\n");
        printf("Dubara cancel nahi ki ja sakti.\n");
        return;
    }

    // Just user ko dikhane ke liye ki konsi ticket cancel ho rhi hai;
    printf("\nTicket Details:\n");
    printf("PNR Number      : %d\n", bookings[bookingIndex].pnr);
    printf("Train Number    : %d\n", bookings[bookingIndex].trainNo);
    printf("Seat Category   : %s\n", bookings[bookingIndex].seatType);
    printf("Total Bill      : INR %.2f\n", bookings[bookingIndex].totalBill);

    //Cancelling the Ticket
    bookings[bookingIndex].status = 0;
    printf("\nTicket ka status CANCELLED kar diya gaya hai.\n\n");

    //Calculating refund and refund details show karna
    cancellationCharge = bookings[bookingIndex].totalBill * 0.20;
    refundAmount = bookings[bookingIndex].totalBill - cancellationCharge;

    printf("\nRefund Details:\n");
    printf("Total Fare           : INR %.2f\n", bookings[bookingIndex].totalBill);
    printf("Cancellation Charge  : INR %.2f\n", cancellationCharge);
    printf("Refund Amount        : INR %.2f\n", refundAmount);

    //Finally correct train dhundna jisme seat update karni hai
    for (int j = 0; j < trainCount; j++) {
        if (trains[j].trainNo == bookings[bookingIndex].trainNo) {
            trainIndex = j;
            break;
        }
    }

    //Seat updation
    if (trainIndex != -1) {
        if (strcmp(bookings[bookingIndex].seatType, "AC") == 0) {
            trains[trainIndex].seatsAC++;
            printf("\n\nAC seat train me wapas add kar di gayi hai.\n");
            printf("Ab available AC seats: %d hain\n", trains[trainIndex].seatsAC);
        }
        else {
            trains[trainIndex].seatsSleeper++;
            printf("\nSleeper seat train me wapas add kar di gayi hai.\n");
            printf("Ab available Sleeper seats: %d hain\n", trains[trainIndex].seatsSleeper);
        }
    }
    else {
        printf("Warning: Train record nahi mila.\n");
        printf("Seat update nahi ho payi.\n");
    }

    // Final message
    printf("\nTicket successfully cancel ho gayi hai.\n");
    printf("Refund process completed.\n");
    printf("Dhanyavaad!\n");
}
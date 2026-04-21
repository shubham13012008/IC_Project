#include "train.h"
 int name_comparison(char str1[], char str2[]){
        int i = 0;
        while(str1[i] != '\0' && str1[i] == str2[i]){
            i++;
        }
        return str1[i] - str2[i];
    }
int adminLogin() {
    char username[20],password[20];
    printf("\n Admin Login ");
    printf("\n Enter Admin ID- ");
    scanf("%s",username);
    printf(" Enter Password- ");
    scanf("%s",password);
   
    if(name_comparison(username,"admin") == 0 && name_comparison(password, "iitj123")==0){
        printf("\nLogin Successful");
        return 1;
    }

    else{
        printf("\n Invalid Credentials ");
        return 0;
    }
}



// Add new train by the admin
void addTrain() {
    if (trainCount >= MAX_TRAINS) {
        printf("[Error] Max. train reached \n");
        return;
    }

    printf("ADD NEW TRAIN DETAILS\n");
    
    printf("Enter Train Number \n ");
    scanf("%d", &trains[trainCount].trainNo);

    printf("Enter Train Name: ");
    scanf("%s", trains[trainCount].naam);
    printf("Enter Source City: ");
    scanf("%s", trains[trainCount].kahanSe);

    printf("Enter Destination City: ");
    scanf("%s", trains[trainCount].kahanTak);

    printf("Enter Date (DD/MM/YYYY): ");
    scanf("%s", trains[trainCount].tarik);

    printf("Enter Departure Time (HHMM): ");
    scanf("%d", &trains[trainCount].depTime);

    printf("Enter Arrival Time (HHMM): ");
    scanf("%d", &trains[trainCount].arrTime);

    printf("Enter AC Fare: ");
    scanf("%f", &trains[trainCount].priceAC);

    printf("Enter Sleeper Fare: ");
    scanf("%f", &trains[trainCount].priceSleeper);

    printf("Total AC Seats: ");
    scanf("%d", &trains[trainCount].seatsAC);

    printf("Total Sleeper Seats: ");
    scanf("%d", &trains[trainCount].seatsSleeper);

    trainCount++; 
    
    printf("Train no.%d added by the addmin \n", trains[trainCount-1].trainNo);
}

void deleteTrain() {
    int tNumber, lokesh = 0;
    printf("Enter Train Number to delete: \n");
    scanf("%d", &tNumber);

    for (int i = 0; i < trainCount; i++) {
        if (trains[i].trainNo == tNumber) {
            for (int j = i; j < trainCount - 1; j++) {
                trains[j] = trains[j + 1];
            }
            trainCount--;
            printf("Train deleted by admin using train no. \n");
            lokesh = 1;
            break;
        }
    }
    if (lokesh != 1) {
        printf("Train not found\n");
    }
}


//Train me badlav by admin;
void editTrain() {
    int dusriTrain, chetan=0;
    printf("\nEnter Train Number to edit: ");
    scanf("%d", &dusriTrain);

    for (int i = 0; i < trainCount; i++) {
        if (trains[i].trainNo == dusriTrain) {
            printf("Editing Train: %s\n", trains[i].naam);
            printf("Enter New AC Fare: ");
            scanf("%f", &trains[i].priceAC);
            printf("Enter New Sleeper Fare: ");
            scanf("%f", &trains[i].priceSleeper);
            printf("Enter New AC Seats: ");
            scanf("%d", &trains[i].seatsAC);
            printf("Enter New Sleeper Seats: ");
            scanf("%d", &trains[i].seatsSleeper);
            
            printf("Train details updated!\n");
            chetan = 1;
            break;
        }
    }
    if (!chetan) printf("Train not found!\n");
}

void displayStats() {
    int total_ac_seats = 0;
    int total_sleeper_seats = 0;
    int booked_ac = 0;
    int booked_sleeper = 0;
    int active_bookings = 0;
    float collected_tax = 0.0;
    float collected_revenue = 0.0;

    for (int i = 0; i < trainCount; i++) {
        total_ac_seats += trains[i].seatsAC;
        total_sleeper_seats += trains[i].seatsSleeper;
    }

    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].status == 1) { 
            active_bookings++;
            collected_revenue += bookings[i].totalBill;
            
            if (strcmp(bookings[i].seatType, "AC") == 0) {
                booked_ac++;
                float base = bookings[i].totalBill / 1.12;
                collected_tax += (bookings[i].totalBill - base);
            } else if (strcmp(bookings[i].seatType, "Sleeper") == 0) {
                booked_sleeper++;
                float base = bookings[i].totalBill / 1.03;
                collected_tax += (bookings[i].totalBill - base);
            }
        }
    }
    printf("            SYSTEM STATISTICS             \n");
    printf("Total Trains Managed  : %d\n", trainCount);
    printf("Total AC Seats        : %d (Available) | %d (Booked)\n", total_ac_seats, booked_ac);
    printf("Total Sleeper Seats   : %d (Available) | %d (Booked)\n", total_sleeper_seats, booked_sleeper);
    printf("Active Bookings       : %d (Out of %d Total)\n", active_bookings, bookingCount);
    printf("Total Revenue         : %.2f INR\n", collected_revenue > 0 ? collected_revenue : totalPaise);
    printf("Total Tax Collected   : %.2f INR\n", collected_tax);
    
}
void adminMenu() {
    if (!adminLogin()) return;

    int chotu;
    while (1) {
        printf("Admin Dashboard\n");
        printf("1. Add New Train\n");
        printf("2. Edit Train Details\n");
        printf("3. Delete Train\n");
        printf("4. View Stats\n");
        printf("5. Back to Main Menu\n");
        printf("Choice: ");
        scanf("%d", &chotu);

        switch (chotu) {
            case 1: addTrain();
            break;
            case 2:editTrain();
            break;
            case 3: deleteTrain();
            break;
            case 4: printf("View stats");
            break;
            case 5: return;
            default: printf("Invalid option!\n");
        }
    }
}

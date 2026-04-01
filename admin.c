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
    scanf("%s",trains[trainCount].naam);
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
#include "train.h"

//Data save karne ke liye functions 
void saveToFile() {

    FILE *lokesh = fopen("train_db.txt", "w");
    FILE *parth = fopen("revenue_info.txt", "w");

    if (lokesh  == NULL || parth   == NULL) {
        printf(" Could  not add train to storagee!\n");
        return;
    }



    // Saving trains using a manual loop
    // First line is the total count

    fprintf(lokesh, "%d\n",  trainCount);
    
    for (int j = 0;  j < trainCount; j++) {
        // Writing each field separated by a comma
        fprintf(lokesh, "%d,%s,%s,%s,%s,%d,%d,%.2f,%.2f,%d,%d\n", 
                trains[j].trainNo, trains[j].naam, trains[j].kahanSe, 
                trains[j].kahanTak, trains[j].tarik, trains[j].depTime, 
                trains[j].arrTime, trains[j].priceAC, trains[j].priceSleeper,
                trains[j].seatsAC, trains[j].seatsSleeper);
    }

    // Saving total money and booking count in a second file
    fprintf(parth, "%.2f %d\n", totalPaise, totalBooking);

    fclose(lokesh);
    fclose(parth);
    
    printf("\n[System] All data written to train_db.txt successfully.\n");
}

// Feature: Load Data at Startup
void loadFromFile() {
    FILE *lokesh =  fopen("train_db.txt", "r");
    FILE *parth =  fopen("revenue_info.txt", "r");

    // If the train file isn't there, it's a first-time run
    if (lokesh   == NULL) {
        printf("\nStarting with an empty database.\n");
        trainCount = 0;
        return;
    }

    // Read the total number of trains first
    if (fscanf(lokesh, "%d", &trainCount) != 1) {
        trainCount = 0;
    }

    // Loop to read each train back into the array
    for (int j = 0;  j < trainCount; j++) {
        int fields = fscanf(lokesh, "%d,%s,%s,%s,%s,%d,%d,%f,%f,%d,%d", 
               &trains[j].trainNo, trains[j].naam, trains[j].kahanSe, 
               trains[j].kahanTak, trains[j].tarik, &trains[j].depTime, 
               &trains[j].arrTime, &trains[j].priceAC, &trains[j].priceSleeper,
               &trains[j].seatsAC, &trains[j].seatsSleeper);
    }

    // Read back the revenue and booking count
    if (parth != NULL) {
        fscanf(parth, "%f %d", &totalPaise, &totalBooking);
        fclose(parth);
    }

    fclose(lokesh);
    printf("\n Successfully loaded %d trains from file.\n", trainCount);
}
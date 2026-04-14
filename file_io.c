#include "train.h"

// Data save karne ke liye functions
void saveToFile() {

  FILE *lokesh = fopen("train_db.txt", "w");
  FILE *parth = fopen("revenue_info.txt", "w");
  FILE *chetan = fopen("bookings.txt", "w");

  if (lokesh == NULL || parth == NULL || chetan == NULL) {
    printf(" Could not add train to storage!\n");
    return;
  }

  // Saving trains

  fprintf(lokesh, "%d\n", trainCount);

  for (int j = 0; j < trainCount; j++) {

    fprintf(lokesh, "%d,%s,%s,%s,%s,%d,%d,%.2f,%.2f,%d,%d\n", trains[j].trainNo,
            trains[j].naam, trains[j].kahanSe, trains[j].kahanTak,
            trains[j].tarik, trains[j].depTime, trains[j].arrTime,
            trains[j].priceAC, trains[j].priceSleeper, trains[j].seatsAC,
            trains[j].seatsSleeper);
  }

  // Saving paise and total booking

  fprintf(parth, "%.2f %d\n", totalPaise, totalBooking);

  // Saving bookings
  fprintf(chetan, "%d\n", bookingCount);
  for (int b = 0; b < bookingCount; b++) {
    fprintf(chetan, "%d,%d,%s,%s,%.2f,%d\n", bookings[b].pnr,
            bookings[b].trainNo, bookings[b].passengerNaam,
            bookings[b].seatType, bookings[b].totalBill, bookings[b].status);
  }

  fclose(lokesh);
  fclose(parth);
  fclose(chetan);

  printf("\n[System] All data written to storage successfully.\n");
}

void loadFromFile() {
  FILE *lokesh = fopen("train_db.txt", "r");
  FILE *parth = fopen("revenue_info.txt", "r");
  FILE *chetan = fopen("bookings.txt", "r");

  // Agar file nhi hai toh nyi file banana
  if (lokesh == NULL) {
    printf("\nStarting with an empty database.\n");
    trainCount = 0;
    bookingCount = 0;
    return;
  }

  // Reading total no. of trains
  if (fscanf(lokesh, "%d", &trainCount) != 1) {
    trainCount = 0;
  }

  // loop for seeing the train
  for (int j = 0; j < trainCount; j++) {
    int fields =
        fscanf(lokesh, "%d,%[^,],%[^,],%[^,],%[^,],%d,%d,%f,%f,%d,%d",
               &trains[j].trainNo, trains[j].naam, trains[j].kahanSe,
               trains[j].kahanTak, trains[j].tarik, &trains[j].depTime,
               &trains[j].arrTime, &trains[j].priceAC, &trains[j].priceSleeper,
               &trains[j].seatsAC, &trains[j].seatsSleeper);
  }

  // seeing revenue and total count

  if (parth != NULL) {
    fscanf(parth, "%f %d", &totalPaise, &totalBooking);
    fclose(parth);
  }

  // seeing bookings
  if (chetan != NULL) {
    if (fscanf(chetan, "%d", &bookingCount) == 1) {
      for (int b = 0; b < bookingCount; b++) {
        fscanf(chetan, "%d,%d,%[^,],%[^,],%f,%d", &bookings[b].pnr,
               &bookings[b].trainNo, bookings[b].passengerNaam,
               bookings[b].seatType, &bookings[b].totalBill,
               &bookings[b].status);
      }
    } else {
      bookingCount = 0;
    }
    fclose(chetan);
  } else {
    bookingCount = 0;
  }

  fclose(lokesh);
  printf("\n Successfully loaded %d trains from file.\n", trainCount);
}

#include "train.h"
void grahakMenu() {
  int parth;
  char s[50], d[50], dt[50];
  while (1) {
    printf("\n---- USER PORTAL ----");
    printf("\n1. Search Trains");
    printf("\n2. Book a Ticket (Using Train Number)");
    printf("\n3. Cancel a Ticket");
    printf("\n4. Back to Main Menu");
    printf("\nChoice: ");
    scanf("%d", &parth);

    switch (parth) {
    case 1: {
      printf("Enter Source: ");
      scanf(" %[^\n]", s);

      printf("Enter Destination: ");
      scanf(" %[^\n]", d);

      printf("Enter Date (DD/MM/YYYY): ");
      scanf("%s", dt);

      int matchCount = 0;
      printf("\nAvailable Trains:\n");
      for (int i = 0; i < trainCount; i++) {
        if (strcmp(trains[i].kahanSe, s) == 0 &&
            strcmp(trains[i].kahanTak, d) == 0 &&
            strcmp(trains[i].tarik, dt) == 0) {
            matchCount++;
            printf("Train No: %d, Name: %s, Dep: %04d, Arr: %04d, AC: %.2f, SL: %.2f\n",
              trains[i].trainNo, trains[i].naam, trains[i].depTime, trains[i].arrTime, trains[i].priceAC, trains[i].priceSleeper);
        }
      }

// Connecting Trains Algo
      if (matchCount == 0) {
        printf("No direct trains found. Searching for connecting trains...\n");

        typedef struct {
          int t1;
          int t2;
          float totalFare;
        } Route;
        Route connect[100];
        int cf = 0; // connectionFound
        // finding a new train from the start  to the middle on samee date
        for (int i = 0; i < trainCount; i++) {
          if (strcmp(trains[i].kahanSe, s) == 0 &&
              strcmp(trains[i].tarik, dt) == 0) {
            for (int j = 0; j < trainCount; j++) {
              // finding a new train from the middle to the destinations
              if (i != j &&
                  strcmp(trains[j].kahanSe, trains[i].kahanTak) == 0 &&
                  strcmp(trains[j].kahanTak, d) == 0 &&
                  strcmp(trains[j].tarik, dt) == 0) {
                // ensuring that there is time to catch the train
                if (trains[j].depTime >= trains[i].arrTime && cf < 100) {
                  connect[cf].t1 = i;
                  connect[cf].t2 = j;
                  connect[cf].totalFare =
                      trains[i].priceSleeper + trains[j].priceSleeper;
                  cf++;
                }
              }
             }
          }
          }

        if (cf == 0) {
          printf("No connecting trains found for this route and date.\n");
        } else {
          // Sorting the  connecting routes based on  minimum price
          for (int m = 0; m < cf - 1; m++) {
            for (int n = 0; n < cf - m - 1; n++) {
              if (connect[n].totalFare > connect[n + 1].totalFare) {
                Route temp = connect[n];
                connect[n] = connect[n + 1];
                connect[n + 1] = temp;
              }
            }
          }

          for (int k = 0; k < cf; k++) {
            int i = connect[k].t1;
            int j = connect[k].t2;
            printf("\nConnection Option %d\n", k + 1);
            printf(
                "  Station 1 : Train No %d (%s)  //%s to %s  //Dep: %04d, Arr: "
                "%04d  //AC: %.2f, SL: %.2f\n",
                trains[i].trainNo, trains[i].naam, trains[i].kahanSe,
                trains[i].kahanTak, trains[i].depTime, trains[i].arrTime,
                trains[i].priceAC, trains[i].priceSleeper);
            printf(
                "  Station 2 : Train No %d (%s)  //%s to %s  //Dep: %04d, Arr: "
                "%04d  //AC: %.2f, SL: %.2f\n",
                trains[j].trainNo, trains[j].naam, trains[j].kahanSe,
                trains[j].kahanTak, trains[j].depTime, trains[j].arrTime,
                trains[j].priceAC, trains[j].priceSleeper);
          }

          int niranjan;
          printf("\nEnter 1 to proceed to booking, or 0 to go back: ");
          scanf("%d", &niranjan);
          if (niranjan == 1) {
            bookTicket();
          }
        }
      } else {
        int niranjan;
        printf("\nEnter 1 to proceed to booking, or 0 to go back: ");
        scanf("%d", &niranjan);
        if (niranjan == 1) {
          bookTicket();
        }
      }
      break;
    }

    case 2:
      bookTicket();
      break;

    case 3:
      cancelTicket();
      break;

    case 4:
      return;

    default:
      printf("Invalid selection\n");
    }
  }
}
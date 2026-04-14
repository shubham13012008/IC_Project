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

      if (matchCount == 0) {
          printf("No trains found for this route and date.\n");
      } else {
          int choice;
          printf("\nEnter 1 to proceed to booking, or 0 to go back: ");
          scanf("%d", &choice);
          if (choice == 1) {
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
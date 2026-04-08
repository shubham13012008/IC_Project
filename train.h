#ifndef TRAIN_H
#define TRAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define MAX_TRAINS 50
#define MAX_BOOKING 100
// Train ka structure admin ke liye store karne ke liye 
typedef struct {
    int trainNo;
    char naam[50];
    char kahanSe[50];
    char kahanTak[50];
    char tarik[15];
    int depTime;        
    int arrTime;        
    float priceAC;      
    float priceSleeper; 
    int seatsAC;
    int seatsSleeper;
} Train;

typedef struct {
    int pnr;
    int trainNo;
    char passengerNaam[50];
    char seatType[10]; 
    float totalBill;       
    int status;           
} Booking;


extern Train trains[MAX_TRAINS];
extern int trainCount;
extern float totalPaise;
extern int totalBooking;

int adminLogin();

void addTrain();
void grahakMenu();
void adminMenu();
void saveToFile();
void loadFromFile();
void editTrain();
void deleteTrain();


#endif
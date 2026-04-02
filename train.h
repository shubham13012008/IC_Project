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


extern Train trains[MAX_TRAINS];
extern int trainCount;

int adminLogin();

void addTrain();
void grahakMenu();
void adminMenu();
void editTrain();
void deleteTrain();


#endif
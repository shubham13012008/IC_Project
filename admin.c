#include "train.h"
 int name_comparison(char str1[], char str2[]){
        int i = 0;
        while(str1[i] != '\0' && str1[i] == str2[i]){
            i++;
        }
        return str1[i] - str2[i];
    }
int adminMenu() {
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
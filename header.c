#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
FILE *stream;
void open(char *of){
    stream=fopen(of, "w");
    struct registry reg;
    char option;
    fputs("NAME, ODIRECTION, PHONE, DATE, HOUR\n", stream);


    do {
    get(&reg);
    print(reg);
        printf("Would you like to add another register? (y or n?) \n");
        option = getchar();
            fflush(stdin);
    }while(option == 'y');
    fclose(stream);
}
void get(struct registry *reg)
{
    printf("NAME:\n"); 
    gets(reg->name);
    printf("ODIRECION\n");
    gets(reg->address);
    printf("PHONE:\n");
    scanf("%i", &reg->phoneNumber);
    fflush(stdin);
    data(reg);

}

void data(struct registry *reg){
struct tm *tp;
time_t segundos;
time(&segundos);
tp = localtime(&segundos);
reg->stDate.day= tp->tm_mday;
reg->stDate.month = tp->tm_mon+1;
reg->stDate.year = tp->tm_year+1900;
reg->stDate.hour = tp->tm_hour;
reg->stDate.minutes = tp->tm_min;
reg->stDate.seconds = tp->tm_sec;
}
void print(struct registry reg){
printf(stream, "%s, %s, %ld, %d/%d/%d %d:%d:%d \n", 
reg.name, reg.address, reg.phoneNumber, reg.stDate.day,
 reg.stDate.month, reg.stDate.year, reg.stDate.hour, 
 reg.stDate.minutes, reg.stDate.seconds);
}
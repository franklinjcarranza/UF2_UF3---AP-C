#ifndef header
#define header

struct date{
	int day;
	int month;
	int year;
	int hour;
	int minutes;
	int seconds;
};

struct registry{
	char name[40];
	char address[40];
	long phoneNumber;
	struct date stDate;
};

#endif 
void open(char []);
void get(struct registry *);
void data(struct registry *);
void print(struct registry);
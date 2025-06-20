#include <stdio.h>
#include <conio.h>

int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int getStartDay(int year) {
    int y = year - 1;
    int d = (1 + 5 * (y % 4) + 4 * (y % 100) + 6 * (y % 400)) % 7;
    return d;
}

void printMonth(int month, int year, int *startDay) {
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int daysInMonth[] = {
        31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    printf("\n\n  ------------ %s %d ------------\n", months[month], year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for (int i = 0; i < *startDay; i++)
        printf("     ");

    for (int day = 1; day <= daysInMonth[month]; day++) {
        printf("%5d", day);
        (*startDay)++;
        if (*startDay > 6) {
            *startDay = 0;
            printf("\n");
        }
    }
    if (*startDay != 0)
        printf("\n");
}

void displayCalendar(int year) {
    int startDay = getStartDay(year);
    for (int month = 0; month < 12; month++) {
        printMonth(month, year, &startDay);
    }
}

int main() {
    int year;
    clrscr();
    printf("Enter Year: ");
    scanf("%d", &year);
    displayCalendar(year);
    getch();
    return 0;
}
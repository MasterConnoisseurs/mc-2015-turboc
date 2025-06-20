#include <stdio.h>
#include <conio.h>

int main() {
    char name[50];

    clrscr();
    printf("Welcome to Turbo C++\n");
    printf("Enter your name: ");
    gets(name);

    printf("Hello %s", name);

    getch();
    return 0;
}

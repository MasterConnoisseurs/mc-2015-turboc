#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void drawGame(char ch, int y, int score) {
    clrscr();
    gotoxy(1, 1);
    printf("Score: %d", score);
    gotoxy(40, y);
    printf("%c", ch);
}

int main() {
    char fallingChar, typedChar;
    int y, score, speed;
    char retry;

    do {
        score = 0;
        speed = 300;

        srand(time(NULL));

        while (1) {
            fallingChar = 'A' + rand() % 26;
            y = 2;

            while (y < 25) {
                drawGame(fallingChar, y, score);
                delay(speed);

                if (kbhit()) {
                    typedChar = getch();
                    if (typedChar == fallingChar || typedChar == fallingChar + 32) {
                        score++;
                        if (speed > 50) speed -= 10;
                        break;
                    } else {
                        goto GameOver;
                    }
                }

                y++;
            }

            if (y == 25) {
                break;
            }
        }

        GameOver:
        clrscr();
        printf("Game Over!\n");
        printf("Your score: %d\n", score);
        printf("Play again? (Y/N): ");
        retry = getch();
    } while (retry == 'Y' || retry == 'y');

    return 0;
}

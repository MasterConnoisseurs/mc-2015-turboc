#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <ctype.h>

#define MAX_LETTERS 5
#define MAX_ROW 20
#define MAX_COL 75
#define DELAY_BASE 150

struct FallingLetter {
    int x, y;
    char ch;
    int active;
};

void initLetter(FallingLetter* fl) {
    fl->x = 2 + rand() % (MAX_COL - 2);
    fl->y = 1;
    fl->ch = 'A' + rand() % 26;
    fl->active = 1;
}

void clearLetter(FallingLetter* fl) {
    gotoxy(fl->x, fl->y);
    cprintf(" ");
}

void drawLetter(FallingLetter* fl) {
    gotoxy(fl->x, fl->y);
    textcolor(LIGHTCYAN);
    cprintf("%c", fl->ch);
}

int main() {
    FallingLetter letters[MAX_LETTERS];
    int score = 0;
    int delayTime = DELAY_BASE;
    int i;
    char typed;

    clrscr();
    randomize();

    for (i = 0; i < MAX_LETTERS; i++)
	letters[i].active = 0;

    while (1) {
	// Spawn new letters randomly
	for (i = 0; i < MAX_LETTERS; i++) {
	    if (!letters[i].active && (rand() % 10 == 0)) {
		initLetter(&letters[i]);
	    }
	}

	// Move and redraw active letters
	for (i = 0; i < MAX_LETTERS; i++) {
	    if (letters[i].active) {
		clearLetter(&letters[i]);
		letters[i].y++;

		if (letters[i].y > MAX_ROW) {
		    letters[i].active = 0;
		    score--;
		} else {
		    drawLetter(&letters[i]);
		}
	    }
	}

	// Display score
	gotoxy(1, MAX_ROW + 2);
	textcolor(WHITE);
	cprintf("Score: %d  ", score);

	// Handle key press
	if (kbhit()) {
	    typed = getch();
	    for (i = 0; i < MAX_LETTERS; i++) {
		if (letters[i].active && toupper(typed) == letters[i].ch) {
		    clearLetter(&letters[i]);
		    letters[i].active = 0;
		    score++;
		    break;
		}
	    }
	}

	delay(delayTime);

	// Increase speed
	if (score > 0 && score % 10 == 0 && delayTime > 30) {
	    delayTime -= 10;
	}

	// Game Over
	if (score < -5) {
	    gotoxy(30, MAX_ROW + 4);
	    textcolor(RED);
	    cprintf("GAME OVER! Final Score: %d", score);
	    break;
	}
    }

    getch();
    return 0;
}

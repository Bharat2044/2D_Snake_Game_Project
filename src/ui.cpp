#include "ui.h"


char border_character = 219;    // 219 -> rectangle bog
void init_ui() {
    initscr();
    nodelay(stdscr, TRUE)   // stop getch to block my input
    noecho();   // stop the echo
    curs_set(0) // remove the cursor
}

void tear_down_ui() {   // to destroy the screen
    endwin();
}

 // to print border  
void paint_border() {  
    // COLS, LINES -> Given by ncurses
    for(int i=0; i<COLS; i++) {     
        move(0, i);
        addch(border_character);

        move(LINES-1, i)
        addch(border_character);
    }

    for(int i=1; i<LINES-1; i++) {  
        move(i, 0);
        addch(border_character);

        move(i, COLS-1)
        addch(border_character);
    }

    // getch();
}
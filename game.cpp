#include "game.h"

int game_state = BEFORE_START;

int direction;

int score;

void start_game() {
    init_snake();    
    init_food();    
    direction = UP;     // initially
    game_state = STARTED;
    score = 0;
}

void end_game() {   
    // end sate -> before_start state   
    game_state = ENDED;
}

void paint_status() {
    move(0, 5);
    printw("Your Score = %d", score);
}

bool game_logic() {   
    paint_border(); 
    paint_status();

    int key = getch();      // blocking input
    
    if(game_state = BEFORE_START) {
        move(10, 10);
        addstr("Press space to start");

        if(key == 32) {     // 32 ASCII value of space
            // start the game
            game_state = STARTED;
        }
    }

    else if(game_state == STARTED) {
        // either keep moving snake or react to key inputs
        if(key == UP && direction != DOWN)
            direction = UP;
        else if(key == DOWN && direction != UP)
            direction = DOWN;
        else if(key == RIGHT && direction != LEFT)
            direction = RIGHT;
        else if(key == LEFT && direction != RIGHT)
            direction = LEFT;

        pair<int, int> head = move_snake(direction);
        // food position => head of snake
        // if its true, then eat the food and grow the snake
        if(try_eating_food(head)) {
            score++;
            grow_snake();
        }
        
        if(has_collision()) {  
            // end the game
            end_game();
        }

        paint_snake();
        paint_food();
    }  

    else {
        // state is ended
        move(10, 10);
        addStr("Game Over: Press space to restart, q to quit");
        if(key == 32) 
            start_game();
        else if(key == 'q')
            return true;    // game over
    }  

    return false;

    // move(x, y);
    // addch('#');
}



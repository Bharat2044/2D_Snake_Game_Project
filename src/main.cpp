#include <iostream>
#include <curses.h>         // install ncurses library and use it
#include "ui.h"
#include "game.h"
#include <chrono>          // this library gives time
#include "setting_constants.h"

using namespace std;


void event_loop() {

    auto last_time = chrono::system_clock::now();
    int dt;         // time difference

    while (true) {      // event -> movement of snake
        auto last_time = chrono::system_clock::now();
        erase();        // ncurses function

        bool game_over = game_logic();
        if(game_over)
            break;
            
        refresh();      // ncurses function

        do {            
            auto current_time = chrono::system_clock::now();       
            dt = chrono::duration_cast<std::chrono::microseconds>(current_time - last_time).count();
        } while(dt < TIME_DELAY_BETWEEN_FRAMES);
        
        // sleep(100);     // maintain the speed - 100ms   => 1sec - 10frames/sec printed
        // 1 sec - 10 frames / sec
        // 0.1 sec - 1 frame
        // 1 sec = 10^6
        // 0.1 -> 10^5 microseconds
    }
    
}

int main() {
    // ncurses put things on a temprory screen
    // initscr();
    // move(10, 10);   // 10th row, 10th col
    // cout << "#" << endl;
    // addch("#");
    // getch();        // stop screen -> waiting to enter any character
    // endwin();       // terminate screen
    // ncurses library
    // command to install ncurses library in Ubuntu  =>  sudo apt-get libncurses6 libncurses6-dev  
    // brew install ncurses


    init_ui();
    event_loop();
    tear_down_ui();
    
    cout << "THANKS FOR PLAYING SNAKE GAME! BUT DON'T BE A SNAKE IN REAL WORLD" << endl;
    
    return 0;
    
    
    // Border looks like
    /*
        #################
        #               #
        #               #
        #               #
        #               #
        #               #
        #               #
        #################
    */
/*
    int height = 20;
    int width = 20;
    // For top row
    for(int i=1; i<=width; i++) 
        cout << "#";
    cout << endl;

    // For height
    for(int i=1; i<=height-2; i++) {
        cout << "#";

        for(int j=1; j<=width-2; j++)
            cout << " ";
        cout << "#";
        cout << endl;
    }

    // For bottom row
    for(int i=1; i<=width; i++) 
        cout << "#";
    cout << endl;
*/    
}
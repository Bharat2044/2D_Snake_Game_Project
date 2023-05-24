#include "food.h"


// place food randomly
// food -> coordinate

vector<pair<int, int>> nibbles;

char food_character = (char)36;  // dollar

pair<int, int> make_food() {
    // randmly generates coordinates
    // bounds x -> 1 ... LINES - 2, y -> 1 ... COLS - 2
    // 1 2 3 4 5 6 7 8 9 10  ->  0 1 2 3 4  ->  N % 5 +1  ->  1 to 5
    return {(rand() % (LINES - 2) + 1), (rand() % (COLS - 2) + 1)};    // 0 -> INT_MAX
}

void init_food() {
    nibbles.clear();
    for(int i=0; i<FOOD_COUNT; i++)
        nibbles.push_back(make_food());
}

void paint_food() {
    for(int i=0; i<nobbles.size(); i++) {
        move(nibbles[i].first, nibbles[i].second);
        addch(food_character);
    }
}

bool try_eating_food(pair<int, int> head) {
    // first check if head == food    
    for(int i=0; i<nobbles.size(); i++) {
        if(head.first == nibbles[i].first, head.second == nibbles[i].second) {
            // eat food
            nibbles.erase(nibbles.begin() + i);   // iterable
            nibbles.push_back(make_food());     // generate more food
            return true;
        }

        return false;
    }
}
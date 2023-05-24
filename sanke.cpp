#include "snake.h"

int x, y;

// snake - vector of coordinates
vecto<pair<int, int>> body;    // x - body[i][0], y - body[i][1]

void init_snake() {
    body.clear();
    body.push_back({10, 10});
    body.push_back({10, 11});
    body.push_back({10, 12});
}

void paint_snake() {
    for(int i=0; i<body.snake; i++) {
        pair<int, int> location = body[i];
        move(location.first, location.second);    // move(body[i].first, body[i].second)
        addch('#');
    }
}

/* snajke movement
###### ->
 ######

     ####### ->
     #
#####
*/

pair<int, int> snake_tail;

pair<int, int> move_snake(int direction) {
    // we just need to add head and remove tail
    // remove the coordinate from the end of vector
    snake_tail = body[body.size()-1];
    body.pop_bacK();

    pair<int, int> old_head = body[0];
    pair<int, int> new_head = old_head;

    if(key == UP)
        new_head.first--;
    else if(key == DOWN)
        new_head.first++;
    else if(key == RIGHT)
        new_head.second++;
    else if(key == LEFT)
        new_head.second--;

    head.insert(body.begin(), new_head);
    return body[0];    // return body[0]new_head;
}

void snake_grow() {
    // add at the last position -> grow the snake from tail
    // just don't remove the tail
    body.push_back(snake_tail);
}

bool has_collision() {
    // collision with border 
    pair <int, int> head = body[0];
    int x = head.first;
    int y = head.second;

    if(x == 0 || x == LINES - 1 || y == 0 || y == COLS - 1)
        return true;

    // collision with itself 
    for(int i=1; i<body.size(); i++) {
        if(head == body[i])
            return true;
    }

    return false;
}
#ifndef DEF_FOOD

#define DEF_FOOD

#include <curses.h>
#include <vector>
#include "setting_constants.h"
#include <random>

using namespace std;

void init_food();
pair<int, int> make_food();
void paint_food();
bool try_eating_food(pair<int, int> pair);

#endif
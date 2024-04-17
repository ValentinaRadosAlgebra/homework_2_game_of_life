#include "game_of_life.h"
#include <iostream>
#include<ctime>
#include <string>
#include <fstream>

game_of_life::game_of_life() {

    for (int i = 0; i < ROWS; ++i) {

        for (int j = 0; j < COLS; ++j) {
            _generation[i][j] = random_value();
        }
    }
}

bool game_of_life::random_value() {
    return rand() % 4 == 0;
}

bool game_of_life::cell_taken(int i, int j) {
    if (i >= 0 and i < ROWS and j >= 0 and j < COLS) {
        return _generation[i][j];
    }
    return false;
}

void game_of_life::next_generation() {
    for (int i = 0; i < ROWS; ++i) {

        for (int j = 0; j < COLS; ++j) {
            int live_neighbors = 0;

            for (int k = -1; k <= 1; ++k) {

                for (int l = -1; l <= 1; ++l) {

                    if (!(k == 0 and l == 0) and cell_taken(i + k, j + l)) {
                        ++live_neighbors;
                    }
                }
            }

            if (_generation[i][j]) {
                _next_generation[i][j] = (live_neighbors == 2 or live_neighbors == 3);
            }
            else {
                _next_generation[i][j] = (live_neighbors == 3);
            }
        }
    }

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            _generation[i][j] = _next_generation[i][j];

        }
    }
}

void game_of_life::draw() {
    cout << endl;
    cout << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (_generation[i][j]) {
                cout << "*";
            }
            else {
                cout << "_";
            }
        }
        cout << endl;
    }
}


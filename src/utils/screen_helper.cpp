#include "screen_helper.h"

int getCenterPosX(int width) {
    int max_x = getmaxx(stdscr);

    int pos_x = (max_x - width) / 2;
    
    return pos_x < 0 ? 0 : pos_x; 
} 

int getCenterPosY(int height) {
    int max_y = getmaxy(stdscr);

    int pos_y = (max_y - height) / 2;
    
    return pos_y < 0 ? 0 : pos_y;
}
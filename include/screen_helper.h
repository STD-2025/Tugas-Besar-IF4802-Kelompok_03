#pragma once

#include <curses.h>

/**
 * @param width The width of the content you want to print
 * 
 * @return The starting x position to print
 */
int getCenterPosX(int width);

/**
 * @param height The width of the content you want to print
 * 
 * @return The starting x position to print
 */
int getCenterPosY(int height);
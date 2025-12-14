#pragma once

#include <curses.h>

typedef struct {
    const char **art;
    const int lines;
} ASCII_ART;

extern ASCII_ART ART_TITLE;
extern ASCII_ART ART_START;
extern ASCII_ART ART_EXIT;
extern ASCII_ART ART_ARROW;

// extern const char *ART_TITLE_DATA[];
// extern const char *ART_START_DATA[];
// extern const char *ART_EXIT_DATA[];
// extern const char *ART_ARROW_DATA[];

/**
 * @param art The ascii art contained in array of char
 * @param lines The number of lines in the art
 * @param pos_y The y position to start printing
 * @param pos_x The x position as alignment
 * 
 * @return Number of lines the ascii art has
 */
int printArt(const char **art, int lines, int pos_y, int pos_x);
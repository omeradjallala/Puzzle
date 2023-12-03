/*
** EPITECH PROJECT, 2021
** myrunner background
** File description:
** manage background of my_runner
*/

#include "../include/my_puzzle.h"

sfVector2i find_jeton(object *gor)
{
    for (int i = 0; i < gor->size; i++)
        for (int n = 0; n < gor->size; n++)
            if (gor->puzzle[i][n].x == LONG + 200 &&
                gor->puzzle[i][n].y == LONG + 200)
                return ((sfVector2i) {n, i});
    return (sfVector2i) {0, 0};
}

void push_piece(object *gor, int y, int x)
{
    sfVector2i jet = find_jeton(gor);
    sfVector2i tmp;

    y += jet.y;
    x += jet.x;
    if (y < 0 || y >= gor->size ||
        x < 0 || x >= gor->size)
        return;
    tmp = gor->puzzle[jet.y][jet.x];
    gor->puzzle[jet.y][jet.x] = gor->puzzle[y][x];
    gor->puzzle[y][x] = tmp;
}

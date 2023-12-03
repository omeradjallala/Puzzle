/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** prototypes of myhunter project
*/

#ifndef _MY_H_
    #define _MY_H_
    #define LONG 600

    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <time.h>
    #include <string.h>
    #include <stdbool.h>

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>

typedef struct object {
    sfEvent event;
    sfClock *clock;
    int score[4];
    sfRenderWindow* window;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2i **puzzle;
    int size;
    int square;

    sfText *sfScore;
    sfFont *font;
} object;

object *build_gor(char **argv);
sfVector2i **build_puzzle(object *gor);
void reinitialize(object *gor, char const *filepath);
sfVector2i *mix_coordonate(object *gor);
int comp(const void *a, const void *b);

sfVector2i find_jeton(object *gor);
int evenment(object *gor);
void displays(object *gor);

void push_piece(object *gor, int x, int y);
int if_end(object *gor);
void the_timer(object *gor);
void score(object *gor);

int game_over(object *gor);

#endif

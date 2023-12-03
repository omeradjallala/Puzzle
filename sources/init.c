/*
** EPITECH PROJECT, 2021
** myrunner background
** File description:
** manage background of my_runner
*/

#include "../include/my_puzzle.h"

object *build_gor(char **argv)
{
    object *gor = malloc(sizeof(object));
    sfVideoMode mode = (sfVideoMode) {LONG, LONG, 32};

    gor->window = sfRenderWindow_create(mode,
        "My Puzzle", sfResize | sfClose, 0);
    gor->size = atoi(argv[2]);
    gor->square = LONG / gor->size;
    gor->clock = sfClock_create();
    gor->sprite = sfSprite_create();
    gor->sfScore = sfText_create();
    gor->font = sfFont_createFromFile("./assets/font.ttf");

    reinitialize(gor, argv[1]);

    sfRenderWindow_drawSprite(gor->window, gor->sprite, 0);
    sfRenderWindow_display(gor->window);
    return (gor);
}

void reinitialize(object *gor, char const *filepath)
{
    for (int i = 0; i < 4; gor->score[i++] = 0);
    gor->texture = sfTexture_createFromFile(filepath, 0);
    sfSprite_setTexture(gor->sprite, gor->texture, sfTrue);
    build_puzzle(gor);
}

sfVector2i **build_puzzle(object *gor)
{
    sfVector2i *tab = mix_coordonate(gor);

    gor->puzzle = malloc(sizeof(sfVector2i*) * gor->size);
    for (int i = 0, t = 0; i < gor->size; i++) {
        gor->puzzle[i] = malloc(sizeof(sfVector2i) * gor->size);
        for (int n = 0; n < gor->size; n++, t++)
            gor->puzzle[i][n] = tab[t];
    }
    free(tab);
    return (gor->puzzle);
}

sfVector2i *mix_coordonate(object *gor)
{
    int const air = gor->size * gor->size;
    sfVector2i *tab = malloc(sizeof(sfVector2i) * air);

    for (int i = 0, t = 0; i < gor->size; i++)
        for (int n = 0; n < gor->size; n++, t++)
            tab[t] = (sfVector2i) {n * gor->square,
                i * gor->square};
    tab[air - 1] = (sfVector2i) {LONG + 200, LONG + 200};
    qsort(tab, air, sizeof(sfVector2i), comp);
    return (tab);
}

int comp(const void *a, const void *b)
{
    return (rand() % 2);
}

/*
** EPITECH PROJECT, 2021
** myrunner background
** File description:
** manage background of my_runner
*/

#include "../include/my_puzzle.h"

int evenment(object *gor)
{
    while (sfRenderWindow_pollEvent(gor->window, &gor->event)) {
        if (gor->event.type == sfEvtClosed)
            sfRenderWindow_close(gor->window);
        sfKeyboard_isKeyPressed(sfKeyUp) ?
            push_piece(gor, 1, 0) :
        sfKeyboard_isKeyPressed(sfKeyDown) ?
            push_piece(gor, -1, 0) :
        sfKeyboard_isKeyPressed(sfKeyRight) ?
            push_piece(gor, 0, -1) :
        sfKeyboard_isKeyPressed(sfKeyLeft) ?
            push_piece(gor, 0, 1) : 0;
    }
    return (sfKeyboard_isKeyPressed(sfKeyR));
}

void displays(object *gor)
{
    sfIntRect rect = {0, 0, gor->square, gor->square};

    for (int i = 0; i < gor->size; i++)
        for (int n = 0; n < gor->size; n++) {
            rect.top = gor->puzzle[i][n].y;
            rect.left = gor->puzzle[i][n].x;
            sfSprite_setTextureRect(gor->sprite, rect);
            sfSprite_setPosition(gor->sprite, (sfVector2f)
                {n * gor->square, i * gor->square});
            sfRenderWindow_drawSprite(gor->window, gor->sprite, NULL);
        }
    sfRenderWindow_drawText(gor->window, gor->sfScore, 0);
}

void free_gor(object *gor)
{
    sfClock_destroy(gor->clock);
    sfSprite_destroy(gor->sprite);
    sfTexture_destroy(gor->texture);
    sfText_destroy(gor->sfScore);
    sfFont_destroy(gor->font);
    sfRenderWindow_destroy(gor->window);
    free(gor);
}

int main(int ac, char **argv)
{
    object *gor = 0;
    int over = 0;

    if (ac != 3 || atoi(argv[2]) < 2 ||
        atoi(argv[2]) > 100) return (84);
    srand(time(0));
    gor = build_gor(argv);
    sleep(2);
    while (sfRenderWindow_isOpen(gor->window)) {
        over = if_end(gor);
        evenment(gor);
        if (!over) {
            displays(gor);
            score(gor);
        } else {
            over = game_over(gor);
            if (over == 1) break;
            if (over == 0) reinitialize(gor, argv[1]);
        }
        sfRenderWindow_display(gor->window);
    }
    free_gor(gor);
    return (0);
}

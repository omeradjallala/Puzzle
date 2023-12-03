/*
 ** EPITECH PROJECT, 2021
** myrunner background
** File description:
** manage background of my_runner
*/

#include "../include/my_puzzle.h"

int if_end(object *gor)
{
    for (int i = 0; i < gor->size; i++)
        for (int n = 0; n < gor->size; n++)
            if (gor->puzzle[i][n].x != LONG + 200 && (
                gor->puzzle[i][n].y != i * gor->square ||
                gor->puzzle[i][n].x != n * gor->square
            ) ) return (0);
    return (1);
}

int game_over(object *gor)
{
    sfVector2i mouse;

    gor->texture = sfTexture_createFromFile("./assets/menu.png", 0);
    sfSprite_setPosition(gor->sprite, (sfVector2f) {0, 0});
    sfSprite_setTexture(gor->sprite, gor->texture, sfTrue);
    sfRenderWindow_drawSprite(gor->window, gor->sprite, 0);

    if (gor->event.type != sfEvtMouseButtonPressed)
        return (-1);
    mouse = sfMouse_getPositionRenderWindow(gor->window);
    if (mouse.y >= 80 && mouse.y <= 200 &&
        mouse.x >= 150 && mouse.x <= 425)
        return (0);
    if (mouse.y >= 350 && mouse.y <= 500 &&
        mouse.x >= 150 && mouse.x <= 425)
        return (1);
    return (-1);
}

void score(object *gor)
{
    char str[6] = "  :  ";

    the_timer(gor);
    str[0] = gor->score[3] + 48;
    str[1] = gor->score[2] + 48;
    str[3] = gor->score[1] + 48;
    str[4] = gor->score[0] + 48;
    sfText_setString(gor->sfScore, str);
    sfText_setFont(gor->sfScore, gor->font);
    sfText_setCharacterSize(gor->sfScore, 40);
    sfText_setPosition(gor->sfScore, (sfVector2f) {0, 20});
}

void the_timer(object *gor)
{
    sfTime time = sfClock_getElapsedTime(gor->clock);

    if (time.microseconds / 1000000.0 >= 1) {
        gor->score[0]++;
        gor->score[0] == 10 ? gor->score[0] = 0, gor->score[1]++ :
        gor->score[1] == 6 ? gor->score[1] = 0, gor->score[2]++ :
        gor->score[2] == 10 ? gor->score[2] = 0, gor->score[3]++ : 0;
        sfClock_restart(gor->clock);
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:58:56 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/22 16:18:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int key(int keycode, t_game *game)
{
    if (keycode == ESC)
        close_game(game);
    if (keycode == UP)
        game->moves += move_up(game);
    if (keycode == DOWN)
        game->moves += move_down(game);
    if (keycode == LEFT)
        game->moves += move_left(game);
    if (keycode == RIGHT)
        game->moves += move_right(game);
    set_win(game);
    return (0);
}

int move_up(t_game *game)
{
    if (game->map[game->player_y - 1][game->player_x] == '0')
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y - 1][game->player_x] = 'P';
        game->player_y--;
    }
    else if (game->map[game->player_y - 1][game->player_x] == 'C')
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y - 1][game->player_x] = 'P';
        game->player_y--;
        game->coin_count--;
    }
    else if (game->map[game->player_y - 1][game->player_x] == 'E' && game->coin_count == 0)
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y - 1][game->player_x] = 'P';
        game->player_y--;
        game->exit--;
        close_game(game);
    }
    else if (game->map[game->player_y - 1][game->player_x] == 'N')
        close_game(game);
    return (1);
}

int move_down(t_game *game)
{
    if (game->map[game->player_y + 1][game->player_x] == '0')
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y + 1][game->player_x] = 'P';
        game->player_y++;
    }
    else if (game->map[game->player_y + 1][game->player_x] == 'C')
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y + 1][game->player_x] = 'P';
        game->player_y++;
        game->coin_count--;
    }
    else if (game->map[game->player_y + 1][game->player_x] == 'E' && game->coin_count == 0)
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y + 1][game->player_x] = 'P';
        game->player_y++;
        game->exit--;
        close_game(game);
    }
    else if (game->map[game->player_y + 1][game->player_x] == 'N')
        close_game(game);
    return (1);
}

int move_right(t_game *game)
{
    if (game->map[game->player_y][game->player_x + 1] == '0')
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y][game->player_x + 1] = 'P';
        game->player_x++;
    }
    else if (game->map[game->player_y][game->player_x + 1] == 'C')
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y][game->player_x + 1] = 'P';
        game->player_x++;
        game->coin_count--;
    }
    else if (game->map[game->player_y][game->player_x + 1] == 'E' && game->coin_count == 0)
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y][game->player_x + 1] = 'P';
        game->player_x++;
        game->exit--;
        close_game(game);
    }
    else if (game->map[game->player_y][game->player_x + 1] == 'N')
        close_game(game);
    return (1);
}

int move_left(t_game *game)
{
    if (game->map[game->player_y][game->player_x - 1] == '0')
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y][game->player_x - 1] = 'P';
        game->player_x--;
    }
    else if (game->map[game->player_y][game->player_x - 1] == 'C')
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y][game->player_x - 1] = 'P';
        game->player_x--;
        game->coin_count--;
    }
    else if (game->map[game->player_y][game->player_x - 1] == 'E' && game->coin_count == 0)
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y][game->player_x - 1] = 'P';
        game->player_x--;
        game->exit--;
        close_game(game);
    }
    else if (game->map[game->player_y][game->player_x - 1] == 'N')
        close_game(game);
    return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:56:11 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/20 20:56:08 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int move_up(t_game *game)
{
    if (game->map[game->player_y - 1][game->player_x] == '1')
        return (0);
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
        game->coin--;
    }
    else if (game->map[game->player_y - 1][game->player_x] == 'E' || game->coin == 0)
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y - 1][game->player_x] = 'P';
        game->player_y--;
        game->exit--;
        close_game(game);
    }
    return (1);
}

int move_down(t_game *game)
{
    if (game->map[game->player_y + 1][game->player_x] == '1')
        return (0);
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
        game->coin--;
    }
    else if (game->map[game->player_y + 1][game->player_x] == 'E' || game->coin == 0)
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y + 1][game->player_x] = 'P';
        game->player_y++;
        game->exit--;
        close_game(game);
    }
    return (1);
}

int move_right(t_game *game)
{
    if (game->map[game->player_y][game->player_x + 1] == '1')
        return (0);
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
        game->coin--;
    }
    else if (game->map[game->player_y][game->player_x + 1] == 'E' && game->coin == 0)
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y][game->player_x + 1] = 'P';
        game->player_x++;
        game->exit--;
        close_game(game);
    }
    return (1);
}

int move_left(t_game *game)
{
    if (game->map[game->player_y][game->player_x - 1] == '1')
        return (0);
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
        game->coin--;
    }
    else if (game->map[game->player_y][game->player_x - 1] == 'E' || game->coin == 0)
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y][game->player_x - 1] = 'P';
        game->player_x--;
        game->exit--;
        close_game(game);
    }
    return (1);
}
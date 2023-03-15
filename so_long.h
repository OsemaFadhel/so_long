/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:15:20 by ofadhel           #+#    #+#             */
/*   Updated: 2023/03/15 19:19:42 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"
# include <unistd.h>

# define TILE_WIDTH 64

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_game
{
    ... /* all sprites */
}               t_game

int close(int keycode, t_vars *vars);

#endif
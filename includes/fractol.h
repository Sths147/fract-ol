/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:26:19 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/30 14:49:31 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "structs.h"
# include <errno.h>
# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000
# define WHITE 0xFFFFFF

int			check_dbl(char *nptr);
void		malloc_error(void);
void		data_init(t_fractal *fractal);
void		events_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		init_fractal(t_fractal *fractal, char *title);
void		init_julia(t_fractal *fractal, char *title, char *real,
				char *imagin);
double		atodbl(char *nptr);
double		linear_tr(double num, double new_min, double new_max,
				double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif
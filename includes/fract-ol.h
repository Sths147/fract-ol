/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:26:19 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/28 16:06:36 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "structs.h"
#include <math.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/cursorfont.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 800
#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF



void	malloc_error(void);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	init_fractal(t_fractal *fractal, char *title);
double	map(double unscaled_num, double new_min, double old_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void	data_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
t_complex	iterate(t_complex number, size_t scale);
void	events_init(t_fractal *fractal);

#endif
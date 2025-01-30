/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:09 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/30 16:39:50 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_fractal *fractal, char *title, char *real, char *imagin)
{
	fractal->x_init = atodbl(real);
	fractal->y_init = atodbl(imagin);
	fractal->title = title;
	fractal->mlx_connexion = mlx_init();
	if (!fractal->mlx_connexion)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connexion, WIDTH, HEIGHT,
			title);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connexion);
		free(fractal->mlx_connexion);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connexion, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
		destroy_img(fractal);
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	if (!fractal->img.pixels_ptr)
		return(free(fractal->img.img_ptr), destroy_img(fractal));
	events_init(fractal);
	data_init(fractal);
}

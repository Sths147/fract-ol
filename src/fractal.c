/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:17:53 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/28 16:35:04 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	size_t		i;
	int			color;
	

	z.x = 0;
	z.y = 0;

	c.x = map(x, -2, +2, 0, WIDTH) + fractal->shift_x;
	c.y = map(y, +2, -2, 0, HEIGHT) + fractal->shift_y;
	i = 0;
	
	/*
	if hypothenuse > 2, then point is out of madelbrot
	*/
	
	while (i < fractal->quality)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{	
			color = map(i, BLACK, WHITE, 0, fractal->quality);
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connexion, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
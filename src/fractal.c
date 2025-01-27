/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:17:53 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/27 17:21:12 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	handle_pixel(int x, int y, t_fractal *fractal, int quality)
{
	t_complex	z;
	t_complex	c;
	size_t		i;

	z.x = 0;
	z.y = 0;

	c.x = map(x, -2, 2, WIDTH);
	c.y = map(x, 2, -2, HEIGHT);
	i = 0;
	
	/*
	if hypothenuse > 2, then point is out of madelbrot
	*/
	
	while (i++ < quality)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{	
			color = map(i, BLACK, WHITE, fractal->quality);
			my_mlx_pixel_put(fractal, x, y, 0x00FFFFFF);
			return ;
		}
	}
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_
		}
	}
}
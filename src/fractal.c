/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:17:53 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/29 14:54:37 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	check_cardioid(double x, double y);

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	size_t		i;
	int			color;

	z.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	
	c = z;
	if (check_cardioid(z.x, z.y))
		return (my_mlx_pixel_put(&fractal->img, x, y, BLACK));
	i = 0;
	while (i < fractal->quality)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{	
			color = map(i, BLACK, WHITE, fractal->quality);
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, BLACK);
}
int	check_cardioid(double x, double y)
{
	double q;

	q = (x - 0.25) * (x - 0.25) + y * y;
	if (q * ( q + (x - 1/4)) < 0.25 * y * y)
		return (1);
	if ((x + 1) * (x + 1) + y * y < 0.0625)
		return (1);
	return (0);
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
			handle_pixel(x++, y, fractal);
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connexion, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
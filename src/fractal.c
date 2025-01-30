/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:17:53 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/30 14:46:52 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			handle_pixel(int x, int y, t_fractal *fractal, int type);
static t_complex	assign_c(t_complex z, t_fractal *fractal, int type);
static void			my_mlx_pixel_put(t_img *data, int x, int y, int color);

void	fractal_render(t_fractal *fractal)
{
	size_t	x;
	size_t	y;
	int		type;

	y = 0;
	if (!ft_strncmp(fractal->title, "mandelbrot", 11))
		type = 0;
	else
		type = 1;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			handle_pixel(x++, y, fractal, type);
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connexion, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}

static void	handle_pixel(int x, int y, t_fractal *fractal, int type)
{
	t_complex	z;
	t_complex	c;
	size_t		i;
	int			color;

	z.x = (linear_tr(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (linear_tr(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	i = 0;
	c = assign_c(z, fractal, type);
	while (i < fractal->quality)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = linear_tr(i, BLACK, WHITE, fractal->quality);
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, BLACK);
}

static t_complex	assign_c(t_complex z, t_fractal *fractal, int type)
{
	t_complex	c;

	if (type == 0)
		c = z;
	else
	{
		c.x = fractal->x_init;
		c.y = fractal->y_init;
	}
	return (c);
}

static void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pixels_ptr + (y * data->line_len + x * (data->bpp >> 3));
	*(unsigned int *)dst = color;
}

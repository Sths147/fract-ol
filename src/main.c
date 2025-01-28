/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:09 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/28 15:00:45 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pixels_ptr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	t_fractal	fractal;
	
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 6)))
	{
		init_fractal(&fractal, av[1]);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connexion);
		return (0);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

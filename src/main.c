/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:09 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/29 15:45:15 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pixels_ptr + (y * data->line_len + x * (data->bpp >> 3));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	t_fractal	fractal;
	
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11)))
	{
		init_fractal(&fractal, av[1]);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connexion);
		return (0);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 6) && !check_dbl(av[2]) && !check_dbl(av[3]))
	{
		init_julia(&fractal, av[1], av[2], av[3]);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connexion);
		return (0);
	}
	else
	{
		write(2, "Error, please put as argument either: \nmandelbrot\njulia <real> <imaginary>\n", 75);
		exit(EXIT_FAILURE);
	}
}

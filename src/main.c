/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:09 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/30 13:34:38 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 6) && !check_dbl(av[2])
		&& !check_dbl(av[3]))
	{
		init_julia(&fractal, av[1], av[2], av[3]);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connexion);
		return (0);
	}
	else
	{
		write(2, "Error, put argument\nmandelbrot\njulia <r> <i>\n", 45);
		exit(EXIT_FAILURE);
	}
}

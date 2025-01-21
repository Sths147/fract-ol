/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:09 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/21 14:12:46 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape || keysym == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	// if (button == 0)
	// {
	// 	mlx_destroy_window(vars->mlx, vars->win);
	// 	exit(0);
	// }
	printf("key pressed: %d\n", keysym);
	return (0);
}

int	stopit(t_vars *vars)
{
	(void)vars;
	// mlx_destroy_window(vars->mlx, vars->win);
	// mlx_destroy_display(vars->mlx);
	// free(vars);
	exit(0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "Hello world!");
	mlx_key_hook(vars.win, close_window, &vars);
	mlx_hook(vars.win, 17, 0, close_window, NULL);
	mlx_loop(vars.mlx);
}

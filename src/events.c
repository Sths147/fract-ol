/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:43:18 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/30 15:50:47 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_handler(int keysym, t_fractal *fractal);
static int	close_handler(t_fractal *fractal);
static int	mouse_handler(int button, int x, int y, t_fractal *fractal);

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
}

static int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= fractal->zoom;
	else if (keysym == XK_Right)
		fractal->shift_x += fractal->zoom;
	else if (keysym == XK_Up)
		fractal->shift_y += fractal->zoom;
	else if (keysym == XK_Down)
		fractal->shift_y -= fractal->zoom;
	else if (keysym == XK_KP_Add)
		fractal->quality += 4;
	else if (keysym == XK_KP_Subtract)
		fractal->quality -= 4;
	if (fractal->quality <= 4)
	{
		ft_printf("Minimum quality reached\n");
		fractal->quality += 4;
	}
	fractal_render(fractal);
	return (0);
}

static int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connexion, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connexion, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connexion);
	free(fractal->mlx_connexion);
	exit(EXIT_SUCCESS);
}

static int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
	{
		fractal->zoom *= 1.2;
		fractal->quality -= 4;
		if (fractal->quality <= 4)
		{
			ft_printf("Minimum quality reached\n");
			fractal->quality += 4;
		}
	}
	else if (button == Button4)
	{
		fractal->zoom *= 0.8;
		fractal->quality += 4;
	}
	(void)y;
	(void)x;
	fractal_render(fractal);
	return (0);
}

#include "fract-ol.h"

void	data_init(t_fractal *fractal);

void	malloc_error(void)
{
	perror("malloc error");
	exit(EXIT_FAILURE);
}

void	init_fractal(t_fractal *fractal, char *title)
{
	fractal->mlx_connexion = mlx_init();
	if (!fractal->mlx_connexion)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connexion, WIDTH, HEIGHT, title);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connexion);
		free(fractal->mlx_connexion);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connexion, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connexion, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connexion);
		free(fractal->mlx_connexion);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}

void	data_init(t_fractal *fractal)
{
	fractal->quality = 10;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->zoom = 1;
}

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connexion, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connexion, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connexion);
	free(fractal->mlx_connexion);
	exit(EXIT_SUCCESS);
}
int	key_handler(int keysym, t_fractal *fractal)
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
		fractal->quality += 2;
	else if (keysym == XK_KP_Subtract)
		fractal->quality -= 2;
	if (fractal->quality <= 2)
	{
		ft_printf("Minimum quality reached\n");
		fractal->quality += 2;
	}
	fractal_render(fractal);
	return (0);
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
	{
		fractal->zoom *= 1.05;
		fractal->quality -= 1;
		if (fractal->quality <= 2)
		{
			ft_printf("Minimum quality reached\n");
			fractal->quality += 2;
		}
	}
	else if (button == Button4)
	{	
		fractal->zoom *= 0.95;
		fractal->quality += 1;
	}
	(void)y;
	(void)x;
	fractal_render(fractal);
	return(0);
}

void events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_handler, fractal);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:50:37 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/30 13:31:45 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	void	*mlx_connexion;
	void	*mlx_window;
	char	*title;
	t_img	img;
	double	shift_x;
	double	shift_y;
	double	x_init;
	double	y_init;
	double	zoom;
	size_t	quality;
}				t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:43:31 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/28 14:40:43 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

t_complex	iterate(t_complex number, size_t scale)
{
	size_t		i;
	t_complex	new;
	double		tmp;

	i = 0;
	new.x = 0.0;
	new.y = 0.0;
	while (i++ < scale)
	{
		tmp = (new.x * new.x) - (new.y * new.y) + number.x;
		new.y = 2 * new.x * new.y + number.y;
		new.x = tmp;
	}
	return (new);
}

double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return (((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min));
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:43:31 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/30 14:16:01 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	linear_tr(double num, double new_min, double new_max, double old_max)
{
	return (((new_max - new_min) * num / old_max + new_min));
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

	result.x = z.x * z.x - z.y * z.y;
	result.y = 2 * z.x * z.y;
	return (result);
}

int	check_dbl(char *nptr)
{
	size_t	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			i++;
		else if (nptr[i] == '.')
			i++;
		else
			return (1);
	}
	return (0);
}

double	atodbl(char *nptr)
{
	size_t	i;
	size_t	k;
	double	result;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i++] - 48;
	}
	if (nptr[i] == '.')
		i++;
	k = 1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result += (nptr[i++] - 48) / pow(10, k++);
	return (result * sign);
}

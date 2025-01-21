#include "includes/fract-ol.h"
#include <stdio.h>

int	main(void)
{
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	size_t		i;

	z.x = 0;
	z.y = 0;
	c.x = 5;
	c.y = 2;
	i = 0;
	while (i++ < 42)
	{
		// z+1 = z2 + c
		tmp.x = z.x * z.x - (z.y * z.y) + z.x;
		tmp.y = 2 * z.x * z.y + z.y;
		z = tmp;
		tmp.x = c.x * c.x - (c.y * c.y) + c.x;
		tmp.y = 2 * c.x * c.y + c.y;
		c = tmp;
		printf("x: %f, y: %f\n", c.x, c.y);
	}
}
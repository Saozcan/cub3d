#include "cub3D.h"

#include "stdio.h"

/* int	wall_check(t_data data, int x, int y)
{
	int i;

	i = 0;
	while (data.wallSize > i)
	{
		if ((x < 0 || x > 700) || (y < 0 || y > 700))
			return (0);
		if (data.wallLocationsX[i] <= x && (data.wallLocationsX[i] + 70) >= x  && \
		( data.wallLocationsY[i] <= y && (data.wallLocationsY[i] + 70) >= y))
			return (1);
		i++;
	}
	return (0);
}
 */

int	wall_check(t_data *data, float x, float y)
{

	(void)data;

	if (x > 300 || y > 300 || x < 0 || y < 0)
		return (0);

	printf("%f %f\n", x, y);

	if ((((int)x == 140) || ((int)x == 210)) && (y > 140.0 && y < 210.0)) {
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, 0xff0000);
		return (1);
	}
	else if ((((int)y == 140) || ((int)y == 210)) && (x > 140.0 && x < 210.0))
	{
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, 0x00ff00);
		return (1);
	}


	/* int i;

	i = 0;
	while (data.wallSize > i)
	{
		if ((x < 0 || x > 700) || (y < 0 || y > 700))
			return (0);
		if (data.wallLocationsX[i] <= x && (data.wallLocationsX[i] + 70) >= x  && \
		( data.wallLocationsY[i] <= y && (data.wallLocationsY[i] + 70) >= y))
			return (1);
		i++;
	} */
	return (0);
}
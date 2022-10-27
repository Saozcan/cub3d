#include "../mlx.h"
#include "../cub3D.h"
#include <stdio.h>

void	img_put_pix(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->new_img_data + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, 500, 500, "Hello!");
	data.new_img = mlx_new_image(data.mlx_ptr, 500, 500);
	data.new_img_data = mlx_get_data_addr(data.new_img, &data.bits_per_pixel, &data.size_line ,&data.endian);
	printf("bits_per == %d size_line == %d endian == %d\n", data.bits_per_pixel, data.size_line, data.endian);
	for (int i = 0; i <= 100; i++)
		img_put_pix(&data, i + 100, i + 100, 0x4f3929);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.new_img, 0, 0);
	mlx_loop(data.mlx_ptr);
	return 0;
}

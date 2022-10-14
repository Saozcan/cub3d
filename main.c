#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#include "mlx.h"

#define PI 3.14159265

typedef struct s_data
{
	void *new_img;
	int *new_img_data;
	void *mlx_ptr;
	void *mlx_win;
	double angle;
	double val;
	double x1;
	double y1;
}	t_data;


char map[10][10] = {
	"1111111111",
	"1000000001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1111111111",
};


void makeRay(t_data *data) {
	double i;
	double x2;
	double y2;
	double tmp;
	
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->new_img, 0, 0);
	mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x1, data->y1, 0xff0000);
	i = 0;
	while (++i < 100) {
		x2 = data->x1 + (i * cos(data->val * (data->angle - 60)));
		tmp = x2 - (int)x2;
		if (tmp > (double)0.5)
			x2 += 1;
		y2 = data->y1 + (i * sin(data->val * (data->angle - 60)));
		tmp = y2 - (int)y2;
		if (tmp > (double)0.5)
			y2 += 1;
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x2, y2, 0xff0000);
	}
	i = 0;
	while (++i < 100) {
		x2 = data->x1 + (i * cos(data->val * (data->angle + 60)));
		y2 = data->y1 + (i * sin(data->val * (data->angle + 60)));
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x2, y2, 0xff0000);
	}
	i = 0;
	while (++i < 100) {
		x2 = data->x1 + (i * cos(data->val * (data->angle)));
		y2 = data->y1 + (i * sin(data->val * (data->angle)));
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x2, y2, 0xff0000);
	}
}

int func(int keypress, void *arg) {

	t_data *data;

	data = (t_data *)arg;

	mlx_clear_window(data->mlx_ptr, data->mlx_win);

	if (keypress == 123)
		data->angle -= 5;
	else if (keypress == 124)
		data->angle += 5;
	else if (keypress == 13) {
		data->y1 = data->y1 + (5 * sin(data->angle * data->val));
		data->x1 = data->x1 + (5 * cos(data->angle * data->val));
	}
	else if (keypress == 1){
		data->y1 = data->y1 - (5 * sin(data->angle * data->val));
		data->x1 = data->x1 - (5 * cos(data->angle * data->val));
	}
	else if (keypress == 0){
		data->y1 = data->y1 - (5 * sin((data->angle + 90) * data->val));
		data->x1 = data->x1 - (5 * cos((data->angle + 90) * data->val));
	}
	else if (keypress == 2){
		data->y1 = data->y1 + (5 * sin((data->angle + 90) * data->val));
		data->x1 = data->x1 + (5 * cos((data->angle + 90) * data->val));
	}
	else if (keypress == 53)
		exit(1);
	makeRay(data);
	return (0);
}

int main() {
	t_data data;


	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, 750, 750, "377266");

 	data.new_img = mlx_new_image(data.mlx_ptr, 300, 300);

	int bits_per_pixel;
	int size_line;
	int endian;
	data.new_img_data = (int *)mlx_get_data_addr(data.new_img, &bits_per_pixel, &size_line, &endian);

	int x;
	int y = 0;
	int i = -1;
	int j;

	while (++i < 10) {
		j = -1;
		while (++j < 10) {
			if (map[i][j] == '1') {
				y = 0;
				while (y <= 28) {
					x = 0;
					while (x <= 28) {
						data.new_img_data[(i * 300 * 30) + (j * 30) + (x + (y * 300))] = 5353205;
						x++;
					}
					y++;
				}
			}
		}
	}
	double angle, val, x1, x2, y1, y2;
	data.val = PI / 180;
	data.angle = 0;
	data.x1 = 100;
	data.y1 = 100;

	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.new_img, 0, 0);
	mlx_hook(data.mlx_win, 2, 0, func, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (0);

	// data.mlx_ptr = mlx_init();
	// data.mlx_win = mlx_new_window(data.mlx_ptr, 480, 480, "Hello");

	
	// mlx_key_hook(data.mlx_win, func, (void *)&data);
	// mlx_loop(data.mlx_ptr);
}

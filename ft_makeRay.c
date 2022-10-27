#include "cub3D.h"
#include <math.h>
#include <stdlib.h>
#include "unistd.h"

#include "stdio.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;

	dest = s;
	while (n-- > 0)
		*dest++ = '\0';
}

void firstArea(t_data *data, int *d_idx) {
	int k;
	float i;
	int checkPozX, checkPozY, checkPozX1, checkPozY1;

	i = data->firstAngle[1];
	while (i < data->firstAngle[0] && i < 90)
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 + (((int)data->y1 % 70) + k)*tan(data->val * i);
			checkPozY = data->y1 - (((int)data->y1 % 70) + k);
			if (wall_check(*data, checkPozX, checkPozY)) {
				break ;
			}
			k += 70;
		}
		k = 0;
		while (k <= 700) {
			checkPozY1 = data->y1 - (70 - ((int)data->x1 % 70) + k)*(1/tan(data->val * i));
			checkPozX1 = data->x1 + (70 - ((int)data->x1 % 70) + k);
			 if (wall_check(*data, checkPozX1, checkPozY1)) {
				break ;
			}
			k += 70;
		}
		if (checkPozX < checkPozX1) {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)))*cos(data->val * (data->angle_distance));
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX, checkPozY);
			// printf("x: %d y: %d", checkPozX, checkPozY);
			// printf("dis: %f\n", data->lastDistances[*d_idx]);
		}
		else {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)))*cos(data->val * (data->angle_distance));
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX1, checkPozY1);
			// printf("x: %d y: %d", checkPozX1, checkPozY1);
			// printf("dis: %f\n", data->lastDistances[*d_idx]);
		}
		i += RAYS;
		data->angle_distance -= RAYS;
	}
}
void secArea(t_data *data, int *d_idx) {
	int k;
	float i;
	int checkPozX, checkPozY, checkPozX1, checkPozY1;

	i = data->secAngle[0];
	while (i > data->secAngle[1])
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 - (((int)data->y1 % 70) + k)*(tan(data->val * i));
			checkPozY = data->y1 - (((int)data->y1 % 70) + k);
			if (wall_check(* data, checkPozX, checkPozY)) {
				break ;
			}
			k += 70;
		}
		k = 0;
		while (k <= 700) {
			checkPozY1 = data->y1 - (((int)data->x1 % 70) + k)*((1/tan(data->val * i)));
			checkPozX1 = data->x1 - (((int)data->x1 % 70) + k);
			if (wall_check(*data, checkPozX1, checkPozY1)) {
				break ;
			}
			k += 70;
		}
		if (checkPozX > checkPozX1) {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)))*cos(data->val * (data->angle_distance));
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX, checkPozY);
			// printf("x: %d y: %d", checkPozX, checkPozY);
			// printf("dis: %f\n", data->lastDistances[*d_idx]);
		}
		else {

			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)))*cos(data->val * (data->angle_distance));
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX1, checkPozY1);
			// printf("x: %d y:%d ", checkPozX1, checkPozY1);
			// printf("dis: %f\n", data->lastDistances[*d_idx]);
		}
		i -= RAYS;
		data->angle_distance -= RAYS;
	}	
}

void thirdArea(t_data *data, int *d_idx) {
	int k;
	float i;
	int checkPozX, checkPozY, checkPozX1, checkPozY1;

	i = data->thirdAngle[1];
	while (i < data->thirdAngle[0] && i < 90)
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 - (70 - ((int)data->y1 % 70) + k)*(tan(data->val * i));
			checkPozY = data->y1 + (70 - ((int)data->y1 % 70) + k);
			if (wall_check(* data, checkPozX, checkPozY)) {
				break ;
			}
			k += 70;
		}
		k = 0;
		while (k <= 700) {
			checkPozY1 = data->y1 + (((int)data->x1 % 70) + k)*((1/tan(data->val * i)));
			checkPozX1 = data->x1 - (((int)data->x1 % 70) + k);
			if (wall_check(*data, checkPozX1, checkPozY1)) {
				break ;
			}
			k += 70;
		}
		if (checkPozX > checkPozX1) {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)))*cos(data->val * (data->angle_distance));
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX, checkPozY);

		}
		else {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)))*cos(data->val * (data->angle_distance));
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX1, checkPozY1);
		}
		i += RAYS;
		data->angle_distance -= RAYS;
	}
}

void fourtArea(t_data *data, int *d_idx) {
	int k;
	float i;
	int checkPozX, checkPozY, checkPozX1, checkPozY1;

	i = data->fourthAngle[0];
	while (i > data->fourthAngle[1])
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 + (70 - ((int)data->y1 % 70) + k)*((tan(data->val * i)));
			checkPozY = data->y1 + (70 - ((int)data->y1 % 70) + k);
			if (wall_check(* data, checkPozX, checkPozY)) {
				break ;
			}
			k += 70;
		}
		k = 0;
 		while (k <= 700) {
			checkPozY1 = data->y1 + (70 - ((int)data->x1 % 70) + k)*(1/(tan(data->val * i)));
			checkPozX1 = data->x1 + (70 - ((int)data->x1 % 70) + k);
			if (wall_check(*data, checkPozX1, checkPozY1)) {
				break ;
			}
			k += 70;
 		}
		if (checkPozX1 > checkPozX) {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)))*cos(data->val * (data->angle_distance));
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX, checkPozY);

		}
		else if (checkPozX1 < checkPozX){
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)))*cos(data->val * (data->angle_distance));
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX1, checkPozY1);
		}
		i -= RAYS;
		data->angle_distance -= RAYS;
	}
}

void makeRay(t_data *data) {
	double i;
	double x2;
	double y2;
	double tmp;

	int d_idx = -1;

	data->angle_distance = 30;

	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->new_img, 0, 0);
	mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x1, data->y1, 0xff0000);
	i = 0;
	while (++i < 500) {
		x2 = data->x1 + (i * cos(data->val * (data->angle - 30)));
		tmp = x2 - (int)x2;
		if (tmp > (double)0.5)
			x2 += 1;
		y2 = data->y1 + (i * sin(data->val * (data->angle - 30)));
		tmp = y2 - (int)y2;
		if (tmp > (double)0.5)
			y2 += 1;
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x2, y2, 0xff0000);
	}
	i = 0;
	while (++i < 500) {
		x2 = data->x1 + (i * cos(data->val * (data->angle + 30)));
		y2 = data->y1 + (i * sin(data->val * (data->angle + 30)));
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x2, y2, 0xff0000);
	}
	i = 0;
	while (++i < 100) {
		x2 = data->x1 + (i * cos(data->val * (data->angle)));
		y2 = data->y1 + (i * sin(data->val * (data->angle)));
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x2, y2, 0xff0000);
	}


	if (((int)data->angle % 360) > 300 && ((int)data->angle % 360) < 330){ 
		//printf("3.koşul\n");
		secArea(data, &d_idx);
		firstArea(data, &d_idx);
		fourtArea(data, &d_idx);
		thirdArea(data, &d_idx);
	}
	else if (((int)data->angle % 360) > 60 && ((int)data->angle % 360) < 330) {
		//printf("1.koşul-%d\n", ((int)data->angle % 360));
		fourtArea(data, &d_idx);
		thirdArea(data, &d_idx);
		secArea(data, &d_idx);
		firstArea(data, &d_idx);
	}
	else{
		//printf("2.koşul-%d\n", ((int)data->angle % 360));
		firstArea(data, &d_idx);
		fourtArea(data, &d_idx);
		thirdArea(data, &d_idx);
		secArea(data, &d_idx);
	}

			
/* 	double checkAngle = abs((int)data->angle % 360);
	if (!(checkAngle > 30 && checkAngle < 240)) {
		if (checkAngle >= 240 && checkAngle <= 300) {
			data->firstAngle[1] = 0;
			data->firstAngle[0] = fabs(210 - checkAngle);
		}
		else if (checkAngle >= 330) {
			data->firstAngle[1] = fabs(300 - checkAngle);
			data->firstAngle[0] = 90;
		}
		else if (checkAngle <= 30) {
			data->firstAngle[1] = fabs(30 + checkAngle);
			data->firstAngle[0] = 90;
		}
		// printf("f: %f, s: %f angle: %f\n", data->firstAngle[0], data->firstAngle[1], checkAngle);

	}
	if (!(checkAngle > 330 && checkAngle < 120)) {
		if (checkAngle >= 120 && checkAngle < 240) {
			data->secAngle[0] = 90;
			if (checkAngle < 210)
				data->secAngle[1] = fabs(checkAngle - 120 - 90);
			else
				data->secAngle[1] = 0;
		}
		else if (checkAngle >= 240) {
			data->secAngle[0] = 90 - fabs(checkAngle - 240);
			data->secAngle[1] = 0;
		}

	}
	if ((checkAngle <= 240 && checkAngle >= 30)) {
		if (checkAngle >= 120 && checkAngle <= 240) {
			data->thirdAngle[0] = 90;
			if (checkAngle >= 150 && checkAngle <= 240)
				data->thirdAngle[1] = 90 - fabs(240 - checkAngle);
			else
				data->thirdAngle[1] = 0;
		}
		else if (checkAngle < 120) {
			data->thirdAngle[0] = 90 - fabs(120 - checkAngle);
			data->thirdAngle[1] = 0;
		}

	}
	if (!(checkAngle < 300 && checkAngle > 150)) {
        if (!(checkAngle < 300 && checkAngle > 60)) {
            data->fourthAngle[0] = 90;
            if (checkAngle >= 300 && checkAngle < 360)
                data->fourthAngle[1] = 90 - fabs(300 - checkAngle);
            else if (!(checkAngle > 30))
                data->fourthAngle[1] = 30 - checkAngle;
            else
                data->thirdAngle[1] = 0;
        }
        else if (checkAngle <= 150) {
            data->fourthAngle[0] = 90 - fabs(60 - checkAngle);
            data->fourthAngle[1] = 0;
        }
	} */
/* 	int j = -1;
	while (++j < 32)
		printf("%d: %f\n", j, data->lastDistances[j]); */

	int	k;
	int l = 0;
	double angle = 30;
	if (data->begin > 0)
		while (l < 960)
		{
			if (data->lastDistances[l] < 1)
				data->lastDistances[l] =1;
			int	pixel_length = 50000/(int)((data->lastDistances[l]));
			if (pixel_length > 1000)
				pixel_length= 1000;
			int begining_y = 500 - (pixel_length/2);
			k = 0;
			while(k < pixel_length){
				if (data->wall_faces[l] == 'N' || data->wall_faces[l] == 'S')
					mlx_pixel_put(data->mlx_ptr, data->win2, l, begining_y, 0xfffffff);
				else
					mlx_pixel_put(data->mlx_ptr, data->win2, l, begining_y, 0xff00000);
				begining_y += 5;
				k+= 5;
			}
			l += 5;
			angle -= RAYS;
		}
		data->begin++;
		mlx_clear_window(data->mlx_ptr, data->win2);

}

/* void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	take_texture(t_data *data, int x, int y, int color, int which_wall)
{
	char	*dst;
	dst = data->new_img_data + (y * data->size_line + x * (data->bits_per_pixel / 8));
	

	*(unsigned int*)dst = color;
} */
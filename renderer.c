#include "define.h"

void render(t_vars *vars)
{
	t_img *img;
	img = (t_img*) malloc(sizeof(t_img));
	img->img = mlx_new_image(vars->mlx, vars->win_width, vars->win_height);
	img->addr = mlx_get_data_addr(img->img, &img->bit_per_pixel, &img->line_lenght, &img->endian);
	for (int y = 0; y < vars->win_height; y++)
	{
		for (int x = 0; x < vars->win_width; x++)
		{
			if (is_collide_point(vars->objects->player, x, y))
			{
				set_pixel(&img->img, x, y, vars->objects->player);
			}
		}
	}

	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	mlx_destroy_image(vars->mlx, img->img);
	free(img);
	
}

void set_pixel(t_img *img, int x, int y, int color)
{
	char **dst;
	dst = (char**) malloc(sizeof(char*));
	*dst = img->addr + (y * img->line_lenght + x * (img->bit_per_pixel / 8));
	*(unsigned int*)*dst = color;
	free(dst);
}
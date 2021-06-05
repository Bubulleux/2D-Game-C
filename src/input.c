#include "define.h"

int key_pressed(int keycode, t_vars *vars)
{
	printf("Key: %d pressed\n", keycode);
}

int key_released(int keycode, t_vars *vars)
{
	printf("Key: %d relase\n", keycode);
}

void init_input(t_vars *vars)
{
    mlx_hook(vars->win, 2, 1L<<0, key_pressed, vars);
	mlx_hook(vars->win, 3, 1L<<1, key_released, vars);
}
# include "define.h"

void update(t_vars *vars)
{
	vars->frame += 1;
	render(vars);
}

void init_objects(t_vars* vars)
{
	vars->objects = (t_objects*) malloc(sizeof(t_objects));
	vars->objects->player = make_square(200, 200, -100, -100, 0x000000FF);
}

int main(void)
{
	t_vars vars;

	vars.frame = 0;
	vars.win_width = 500;
	vars.win_height = 500;

	init_objects(&vars);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height, "2D Game 2");
	mlx_loop_hook(vars.mlx, update, &vars);

	mlx_loop(vars.mlx);
}
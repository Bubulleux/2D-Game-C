# include "define.h"



void update(t_vars *vars)
{
	vars->frame += 1;
	render(vars);
}


int main(void)
{
	t_vars vars;

	vars.frame = 0;

	init_objects(&vars);

	vars.mlx = mlx_init();

	mlx_loop_hook(vars.mlx, update, &vars);
	mlx_loop(vars.mlx);
}
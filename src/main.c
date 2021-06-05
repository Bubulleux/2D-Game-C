# include "define.h"



int update(t_vars *vars)
{
	vars->frame += 1;
	render(vars);
}


int main(void)
{
	t_vars vars;

	vars.frame = 0;

	vars.mlx = mlx_init();

	init_renderer(&vars);
	init_objects(&vars);
	init_input(&vars);

	mlx_loop_hook(vars.mlx, update, &vars);
	mlx_loop(vars.mlx);
}
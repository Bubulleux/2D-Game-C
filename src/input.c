#include "define.h"

int key_pressed(int keycode, t_vars *vars)
{
	if (get_index(vars->input_vars, keycode) != -1 && !get_input(vars->input_vars, keycode))
	{
		set_input(vars->input_vars, keycode, true);
	}
}

int key_released(int keycode, t_vars *vars)
{
	if (get_index(vars->input_vars, keycode) != -1 && get_input(vars->input_vars, keycode))
	{
		set_input(vars->input_vars, keycode, false);
	}
}

void init_input(t_vars *vars)
{
    mlx_hook(vars->win, 2, 1L<<0, key_pressed, vars);
	mlx_hook(vars->win, 3, 1L<<1, key_released, vars);
	vars->input_vars = malloc(sizeof(t_input_vars));
	// vars->input_vars->inputs_pressed = (int **) malloc(sizeof(int *) * 4);
	
	vars->input_vars->inputs_pressed = malloc(4 * sizeof(int *));
	for (int i = 0; i < 4; i++)
	{
		vars->input_vars->inputs_pressed[i] = malloc(sizeof(int) * 2);
	}
	vars->input_vars->inputs_pressed[0][0] = UP_ARROW;
	vars->input_vars->inputs_pressed[1][0] = DOWN_ARROW;
	vars->input_vars->inputs_pressed[2][0] = LEFT_ARROW;
	vars->input_vars->inputs_pressed[3][0] = RIGHT_ARROW;
}

void set_input(t_input_vars *input_vars, int input, bool state)
{
	input_vars->inputs_pressed[get_index(input_vars, input)][1] = state ? 1 : 0;
}

bool get_input(t_input_vars *input_vars, int input)
{
	return input_vars->inputs_pressed[get_index(input_vars, input)][1] == 1;
}

int get_index(t_input_vars *input_vars, int input)
{
	for (int i = 0; i < 4; i++)
	{
		if (input_vars->inputs_pressed[i][0] == input)
		{
			return i;
		}
	}


	return -1;
}
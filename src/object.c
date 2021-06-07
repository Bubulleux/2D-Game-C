#include "define.h"

void init_objects(t_vars *vars)
{
	vars->objects = (t_objects*) malloc(sizeof(t_objects));
	vars->objects->player = make_square(50, 50, 50, 50, 0x00ff00ff);
	vars->objects->box = make_square(235, 235, 30, 30, 0x00ff0000);
	vars->objects->background = make_square(0, 0, vars->win_width, vars->win_height, 0x00999999);
}

void update_object(t_vars *vars)
{
	set_player_pose(vars);
}

void set_player_pose(t_vars *vars)
{
	t_input_vars *intput_v = vars->input_vars;
	t_square *ply = vars->objects->player;
	int x = ply->pos_x + (get_input(intput_v, LEFT_ARROW) * -1) + (get_input(intput_v, RIGHT_ARROW) * 1);
	int y = ply->pos_y + (get_input(intput_v, UP_ARROW) * -1) + (get_input(intput_v, DOWN_ARROW) * 1);
	//mlx_mouse_get_pos(vars->mlx, vars->win, &x, &y);

	t_square* futur_player = make_square(x, y, 50, 50, 0);
	if (is_collide_point(vars->objects->background, x, y) && !is_collide(vars->objects->box, futur_player))
	{
		ply->pos_x = x;
		ply->pos_y = y;
	}
	free(futur_player);
}

t_square* make_square(int pos_x, int pos_y, int size_x, int size_y, int color)
{
	t_square* square = (t_square*) malloc(sizeof(t_square));
	square->pos_x = pos_x;
	square->pos_y = pos_y;
	square->size_x = size_x;
	square->size_y = size_y;
	square->color = color;
	return square;
}


bool is_collide(t_square *square_a, t_square *square_b)
{
	// printf("%d ", square_a->pos_x > (square_b->pos_x + square_b->size_x));
	// printf("%d ", (square_a->pos_x + square_a->size_x) < square_b->pos_x);
	// printf("%d ", square_a->pos_y > (square_b->pos_y + square_b->size_y));
	// printf("%d ", (square_a->pos_y + square_a->size_y) < square_b->pos_y);
	// printf("\n");

	if (square_a->pos_x > (square_b->pos_x + square_b->size_x) ||
		(square_a->pos_x + square_a->size_x) < square_b->pos_x ||
		square_a->pos_y > (square_b->pos_y + square_b->size_y) ||
		(square_a->pos_y + square_a->size_y) < square_b->pos_y)

		return false;
	else
		return true;
}

bool is_collide_point(t_square *square, int x, int y)
{
	if ((x < square->pos_x || x > square->pos_x + square->size_x) ||
		(y < square->pos_y || y > square->pos_y + square->size_y))
		
		return false;
	else
	{
		//printf("x: %d, y: %d, square: %d %d %d %d\n", x, y, square->pos_x, square->pos_y, square->size_x, square->size_y);
		return true;
	}
}


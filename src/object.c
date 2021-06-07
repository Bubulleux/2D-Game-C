#include "define.h"

void init_objects(t_vars *vars)
{
	vars->objects = (t_objects*) malloc(sizeof(t_objects));
	vars->objects->player = make_square(make_vector(50, 50), make_vector(50, 50), 0x00ff00ff);
	vars->objects->box = make_square(make_vector(235, 235), make_vector(30, 30), 0x00ff0000);
	vars->objects->background = make_square(make_vector(0, 0), make_vector(vars->win_width, vars->win_height), 0x00999999);
}

void update_object(t_vars *vars)
{
	set_player_pose(vars);
}

void set_player_pose(t_vars *vars)
{
	t_input_vars *intput_v = vars->input_vars;
	t_square *ply = vars->objects->player;

	t_vector *velocity = make_vector(
	(get_input(intput_v, LEFT_ARROW) * -1) + (get_input(intput_v, RIGHT_ARROW) * 1),
	(get_input(intput_v, UP_ARROW) * -1) + (get_input(intput_v, DOWN_ARROW) * 1));

	normalize_vector(velocity, velocity);
	velocity->x = velocity->x * PLY_SPEED * vars->time->delta_time;
	velocity->y = velocity->y * PLY_SPEED * vars->time->delta_time;

	//printf("\r%f", ((get_input(intput_v, UP_ARROW) * -1) + (get_input(intput_v, DOWN_ARROW) * 1)) * 1000.0 * vars->time->delta_time);
	t_vector *futur_pos = make_vector(velocity->x + ply->pos->x, velocity->y + ply->pos->y);

	t_square* futur_player = make_square(futur_pos, ply->size, 0);
	if (!is_collide(vars->objects->box, futur_player))
	{
		free_vector(ply->pos);
		ply->pos = futur_pos;
	}
	free(futur_player);
}

t_square* make_square(t_vector *pos, t_vector *size, int color)
{
	t_square* square = (t_square*) malloc(sizeof(t_square));
	square->pos = pos;
	square->size = size;
	square->color = color;
	return square;
}




bool is_collide(t_square *square_a, t_square *square_b)
{
	// printf("%d ", square_a->pos_x > (bp->x + bs->x));
	// printf("%d ", (square_a->pos_x + as->x) < bp->x);
	// printf("%d ", ap->y > (bp->y + bs->y));
	// printf("%d ", (ap->y + as->y) < bp->y);
	// printf("\n");
	t_vector *ap = square_a->pos;
	t_vector *as = square_a->size;

	t_vector *bp = square_b->pos;
	t_vector *bs = square_b->size;

	if (ap->x > (bp->x + bs->x) || (ap->x + as->x) < bp->x ||
		ap->y > (bp->y + bs->y) || (ap->y + as->y) < bp->y)

		return false;
	else
		return true;
}

bool is_collide_point(t_square *square, t_vector *point)
{
	if ((point->x < square->pos->x || point->x > square->pos->x + square->size->x) ||
		(point->y < square->pos->y || point->y > square->pos->y + square->size->y))
		
		return false;
	else
	{
		//printf("x: %d, y: %d, square: %d %d %d %d\n", x, y, square->pos_x, square->pos_y, square->size_x, square->size_y);
		return true;
	}
}


#include "define.h"

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

bool is_collide(t_square* square_a, t_square* square_b)
{

	if (square_a->pos_x > square_b->pos_x + square_b->size_x ||
		square_a->pos_x + square_a->size_x < square_b->size_x ||
		square_a->pos_y > square_b->pos_y + square_b->size_y ||
		square_a->pos_y + square_a->size_y < square_b->size_y)

		return false;
	else
		return true;
}

bool is_collide_point(t_square* square, int x, int y)
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


#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>







typedef struct s_img
{
	void *img;
	char *addr;
	int bit_per_pixel;
	int line_lenght;
	int endian;
} t_img;

typedef struct s_square
{
	int pos_x;
	int pos_y;
	int size_x;
	int size_y;
	int color;
} t_square;

typedef struct s_objects
{
	t_square* player;
} t_objects;

typedef struct s_vars 
{
	void *mlx;
	void *win;
	unsigned int win_width;
	unsigned int win_height;
	unsigned int frame;

	t_objects* objects;
} t_vars;


//Render
void render(t_vars *vars);
void set_pixel(t_img *img, int x, int y, int color);

//Main
void update(t_vars *vars);
void init_objects(t_vars* vars);

//Square
t_square* make_square(int pos_x, int pos_y, int size_x, int size_y, int color);
bool is_collide(t_square* square_a, t_square* square_b);
bool is_collide_point(t_square* square, int x, int y);
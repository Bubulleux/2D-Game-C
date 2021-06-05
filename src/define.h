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
	t_square* box;
	t_square* background;
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




//main.c
void update(t_vars *vars);
void init_objects(t_vars* vars);

//object.c
void init_objects(t_vars* vars);
void update_object(t_vars* vars);
void set_player_pose(t_vars* vars);
t_square* make_square(int pos_x, int pos_y, int size_x, int size_y, int color);
bool is_collide(t_square* square_a, t_square* square_b);
bool is_collide_point(t_square* square, int x, int y);

//renderer.c
void init_renderer(t_vars vars);
void render(t_vars *vars);
void render_square(t_vars* vars, t_square* square, t_img* img);
void set_pixel(t_img *img, int x, int y, int color);

//input.c
void key_pressed(int keycode, t_vars *vars);
void key_released(int keycode, t_vars *vars);
void init_input(t_vars vars);



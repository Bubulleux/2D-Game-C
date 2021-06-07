#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//#include <inttypes.h>
#include <math.h>

//------------Const------------
//Inpute
#define UP_ARROW 65362
#define DOWN_ARROW 65364
#define LEFT_ARROW 65361
#define RIGHT_ARROW 65363

#define FPS 60.0
#define PLY_SPEED 250.0

//------------Struct------------
typedef struct s_img
{
	void *img;
	char *addr;
	int bit_per_pixel;
	int line_lenght;
	int endian;
} t_img;

typedef struct s_vector
{
	double x;
	double y;
} t_vector;

typedef struct s_square
{
	t_vector *pos;
	t_vector *size;
	int color;
} t_square;

typedef struct s_objects
{
	t_square *player;
	t_square *box;
	t_square *background;
} t_objects;

typedef struct s_input_vars
{
	int **inputs_pressed;
} t_input_vars;

typedef struct s_time
{
	float delta_time;
	long last_time_value;
} t_time;

typedef struct s_vars 
{
	void *mlx;
	void *win;
	unsigned int win_width;
	unsigned int win_height;
	unsigned int frame;

	t_objects *objects;
	t_input_vars *input_vars;
	t_time *time;
} t_vars;


//------------Function------------

//main.c
long long current_timestamp();
int update(t_vars *vars);
void maint(void);

//object.c
void init_objects(t_vars *vars);
void update_object(t_vars *vars);
void set_player_pose(t_vars *vars);
void free_square(t_square *square);
t_square* make_square(t_vector *pos, t_vector *size, int color);
bool is_collide(t_square *square_a, t_square *square_b);
bool is_collide_point(t_square *square, t_vector *point);

//renderer.c
void init_renderer(t_vars *vars);
void render(t_vars *vars);
void render_square(t_vars *vars, t_square *square, t_img *img);
void set_pixel(t_img *img, int x, int y, int color);

//input.c
int key_pressed(int keycode, t_vars *vars);
int key_released(int keycode, t_vars *vars);
void init_input(t_vars *vars);
void set_input(t_input_vars *input_vars, int input, bool state);
bool get_input(t_input_vars *input_vars, int input);
int get_index(t_input_vars *input_vars, int input);

//error.c
void error(char *error);

//vector.c
t_vector* make_vector(double x, double y);
void free_vector(t_vector *vector);
// t_vector* add_vector(t_vector *vector_a, t_vector *vector_b);
// t_vector* substract_vector(t_vector *vector_a, t_vector *vector_b);
// t_vector* multiplie_vector(t_vector *vector_a, t_vector *vector_b);
// t_vector* divide_vector(t_vector *vector_a, t_vector *vector_b);
void normalize_vector(t_vector *vector_a, t_vector *vector_b);
double get_magnetude_vector(t_vector *vector);

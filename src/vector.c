#include "define.h"

t_vector* make_vector(double x, double y)
{
    t_vector *vector = malloc(sizeof(t_vector));
    vector->x = x;
    vector->y = y;
    return vector;
}

void free_vector(t_vector *vector) { free(vector); }

void normalize_vector(t_vector *vector_a, t_vector *vector_b)
{
    double magnetude = get_magnetude_vector(vector_a);
    vector_b->x = vector_a->x / magnetude;
    vector_b->y = vector_a->y / magnetude;
}

double get_magnetude_vector(t_vector *vector)
{
    return sqrt(pow(vector->x, 2) + pow(vector->y, 2));
}

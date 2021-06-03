

# gcc -I/usr/include -O3 -I/usr/include/mlx -g -c -o main.o main.c 
# gcc -o main main.o -L/usr/include/mlx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd
rm main

gcc  -o main main.c renderer.c square.c -g -I ./ -I/usr/include -O3 -I/usr/include/mlx -g -L/usr/include/mlx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd
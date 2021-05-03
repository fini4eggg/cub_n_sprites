#ifndef CUB3D
# define CUB3D

#include <string.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include <fcntl.h>
#include "./libft/libft.h"
#include "get_next_line.h"

#define g_rspeed 0.12
#define g_mspeed 0.2

typedef struct	s_params
{
	int			width;
	int			height;
	char		*so_path;
	char		*no_path;
	char		*we_path;
	char		*ea_path;
	char		*s_path;
	int			flclr;
	int			clclr;
	int			save;
	int			params_fillment;
	char		**map;
	int			player;
}				t_params;

typedef struct  s_data 
{
	void		*img;
	char		*addr;
	int		 bits_per_pixel;
	int		 line_length;
	int		 endian;
	int			width;
	int			height;
}			   t_data;

typedef struct	s_ray
{
	double		dirX;
	double		dirY;
	double		playerX;
	double		playerY;
	double		planeX;
	double		planeY;
	double		rayDirX;
	double		rayDirY;
	double		cameraX;
	double		cameraY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	int			stepX;
	int			stepY;
	int			mapX;
	int			mapY;
	int			hit;
	int			color;
	int			side;
	float		wallx;
	int			texx;
	int			texy;
	float		texpos;
	float		step;
	double		perpWallDist;
	int			**buf;
}				t_ray;

typedef struct s_key
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		stepl;
	int		stepr;
	int		exit;
}				t_key;

typedef struct s_sprite
{
	float	x;
	float	y;
	int		order;
	float	distance;
}				t_sprite;

typedef struct s_spritecast
{
	double		*zbuffer;
	double 		spriteX;
	double 		spriteY;
	double 		invDet;
	double 		transformX;
	double 		transformY;
	int 		spriteScreenX;
	int 		spriteHeight;
	int 		drawStartY;
	int 		drawEndY;
	int 		spriteWidth;
	int 		drawStartX;
	int 		drawEndX;
	int 		texX;
	int 		d;
	int 		texY;
	int			cnt;
	int			color;
}			t_spritecast;

typedef struct s_bmp
{
	unsigned char	*header[54];
	int				size;
	int				fd;
	int				color;
}				t_bmp;

typedef struct s_cub
{
	void 			*mlx;
	void 			*win;
	char			**map;
	int				map_w;
	int				map_h;
	t_ray			ray;
	t_data 			img;
	t_params 		list;
	t_key			key;
	t_data			north;
	t_data			south;
	t_data			east;
	t_data			west;
	t_data			sprite;
	t_data			current;
	t_sprite		*sprites;
	t_spritecast	sprcast;
	t_bmp			bmp;
}				t_cub;
// parser.c
int	 	check_resol_posit(char **res, t_params *list);
int	 	check_resol(char *line, t_params *list);
int	 	check_so_path(char *line, t_params *list);
int	 	check_no_path(char *line, t_params *list);
int	 	check_we_path(char *line, t_params *list);
int	 	check_ea_path(char *line, t_params *list);
int	 	check_s_path(char *line, t_params *list);
int	 	check_floor_path(char *line, t_params *list);
int	 	check_celing_path(char *line, t_params *list);
int	 	check_params_fill(t_params *list);
int	 	check_params(char *line, t_params *list);
char	**make_map(t_list **head, int size);
int		make_rectangle(t_cub *cub, char **map);
int 	check_char(int c, char *compare);
int		check_around(char **map, int i, int j, char *compare);
void	set_player(t_cub *cub);
int		check_validity(char **map, t_cub *cub);
void	ft_init(t_cub *cub);
// raycasting.c
void	check_max_res(t_cub *cub);
void	check_max_res(t_cub *cub);
void 	init_txt(t_cub *cub);
int 	key_release(int key, t_cub *cub);
int 	key_press(int key, t_cub *cub);
int		read_keys(t_cub *cub);
int		ray_casting(t_cub *cub);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void 	draw_walls(t_cub *cub, int x);
void 	chose_txt(t_cub *cub);
void 	dda(t_cub *cub);
void	calc_steps(t_cub *cub);
void	wall_cast(t_cub *cub, int x);

int			get_next_line(int fd, char **line);
int			ray_casting(t_cub *cub);
int			draw(t_cub *cub);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		set_sprites(t_cub *cub);
void		cast_sprites(t_cub *cub);
void		screenshot(t_cub *cub);

void		stripe (t_cub *cub);

#endif
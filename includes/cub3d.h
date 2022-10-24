#ifndef CUB3D_H
# define CUB3D_H

# include "ft_color.h"
# include "../Libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

#define BLACK_PIXEL 0x000000
#define GRAY_PIXEL 0x808080
#define WHITE_PIXEL 0xFFFFFF
#define GREEN_PIXEL 0x33FF66
#define YELLOW_PIXEL 0xFFFF66

# define BUFFER_SIZE 1024
# define PIX 64
# define W_WIDTH 1024//512 //1500 //400 //1920
# define W_HEIGHT 512//512 //920 //301 //1080

#define PI 3.14159265359
#define DR 0.0174533 // one degree in radians

// typedef struct s_img
// {
// 	void		*visuel;
// 	char		*addr;
// 	// int			*w;
// 	// int			*h;
// 	int			bitspp;
// 	int			line_length;
// 	int			endian;
// }				t_img;


typedef struct s_rays
{
	int		r;
	int 	mx;
	int		my;
	int		mp;
	int 	dof;
	double	rx;
	double	ry;
	double	ra;
	double	xo;
	double	yo;
	double	distH;
	double  distV;
	double	distF;
	double	hx;
	double	hy;
	double 	vx;
	double	vy;
}				t_rays;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			width;
	int			height;
	t_img		*imgame;
	// t_img		coll;
	// t_img		player;
	// t_img		ground;
	// t_img		wall;
	// t_img		exit;
}				t_mlx;

typedef struct s_player
{
	int			key_r;
	int			key_l;
	int			key_w;
	int			key_s;
	int			move;
	int			px;
	int			py;
	int			x;
	int			y;
	double		pdx;
	double		pdy; 
	double		pa; //angle of the player en radians
}				t_player;

typedef struct s_map
{
	int			*map;
	int			nbexit;
	int			sizeline;
	int			nbline;
	int			px;
	int			py;
	int			mapS;
	int			other;
	int			error;
	char	name[BUFFER_SIZE];
	char	tex_no[BUFFER_SIZE];
	char	tex_so[BUFFER_SIZE];
	char	tex_we[BUFFER_SIZE];
	char	tex_ea[BUFFER_SIZE];
	int		flo;
	int		cel;
	int		fd;
	//t_player	*player;
}				t_map;

typedef struct s_admin
{
	t_map		*map;
	t_mlx		*mlx;
	t_player	*player;
	t_rays		*rays;
}				t_admin;


/*--------------------GRAPHICAL PART----------------------*/



//--rendu affichage--//

void	black_image(t_admin *admin);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

//--rendu affichage minimap----//

int	render(t_admin *admin);
void	drawPlayer(t_admin *admin, t_mlx *mlx, t_player *player);

void	color_cube(t_mlx *mlx, t_map *map, int color);
void	drawMap2D(t_mlx *mlx, t_map *map);

//--rayon 3D---//

double	get_dist(double px, double py, double hvx, double hvy);
void	drawLine(t_admin *admin, t_mlx *mlx);
void 	draw_Wall(t_admin *admin, t_map *map, t_mlx *mlx, double dist);

void	Rays_distancecheck(t_player *player, t_rays *rays, t_map *map, int order);
void	Rays_horizontalcheck(t_player *player, t_rays *rays);
void	Rays_verticalcheck(t_player *player, t_rays *rays);
void	drawRays3D(t_admin *admin, t_player *player, t_rays *rays, t_map *map);
//void	drawRays3Dold(t_admin *admin, t_player *player, t_rays *rays, t_map *map);
//void	drawRays3DVerti(t_admin *admin, t_player *player, t_rays *rays, t_map *map);

//---Interpretation keyboard---//

//int	ft_readkey(int keycode, t_admin *admin); ancienne version//
void	turn_right(t_player *player);
void	turn_left(t_player *player);
void	move_up(t_map *map, t_player *player);
void	move_down(t_map *map, t_player *player);

int	key_pressed(int keycode, t_admin *admin);
int	key_released(int keycode, t_admin *admin);
void	use_key(t_admin *admin);

//--manipulation du tableau int - MAP ----//

int	get_int(int x, int y, t_map *map);
int	get_coord(int x, t_map *map);

//--launch-----//

int	main(void);
void	init_struct(t_admin *admin);
int	mlx_start_init(t_mlx *mlx, t_admin *admin);

//--close------//

int	ft_closeok(t_admin *admin);
int	ft_close(t_admin *admin);

/*
*---------------PARSING PART----------------------------------*
*/

/*
 * === ft_error === *
 */

int		ft_error_int(char *e, int x);

/*
 * === parsing === *
 */

int		ft_check_elems(t_map *map);
int		ft_check_name(t_map *map);
int		ft_fill_col(char *l, int end, int r, int i);
bool	ft_isdigit_cub(char *s, int n);
int		ft_parsing(t_map *map, char *str);
void	ft_save_elems(t_map *map, char *l);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:40:30 by cgranja           #+#    #+#             */
/*   Updated: 2022/10/30 17:40:34 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define BLACK_PIXEL 0x000000
# define GRAY_PIXEL 0x808080
# define GRAY_PL_PIXEL 0x666666
# define WHITE_PIXEL 0xFFFFFF
# define GREEN_PIXEL 0x33FF66
# define FGREEN_PIXEL 0x21A342
# define YELLOW_PIXEL 0xFFFF66
# define CYAN_PIXEL 0x00CCCC

# define BUFFER_SIZE 1024
# define PIX 64
# define W_WIDTH 1219//1024//512 //1500 //400 //1920
# define W_HEIGHT 914//512//512 //920 //301 //1080

# define SPEED 1.5
# define PI 3.14159265359
# define DR 0.0174533 // one degree in radians, pi/180

# define TEXT_H 64
# define TEXT_W 64

typedef struct s_rays
{
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	int		map_dof;
	double	rx; //coordonnee x de l'impact du rayon sur une intersection
	double	ry;
	double	ra; //angle du rayon
	double	xo;
	double	yo;
	double	disth;
	double	distv;
	double	distfin;
	double	hx;
	double	hy;
	double	vx;
	double	vy;
	int		color;
}				t_rays;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			width;
	int			height;
	t_img		*imgame;
}				t_mlx;

typedef struct s_player
{
	int			key_r;
	int			key_l;
	int			key_w;
	int			key_s;
	int			key_fr;
	int			key_fl;
	int			move;
	int			px;
	int			py;
	int			x;
	int			y;
	double		pdx; //deltax pour la rota player
	double		pdy;
	double		pa; //angle of the player en radians
	char		text;
}				t_player;

typedef struct s_text
{
	char		*text_n;
	char		*text_s;
	char		*text_e;
	char		*text_w;
	t_img		*te;
	t_img		*tw;
	t_img		*ts;
	t_img		*tn;
	float		tx;
	float		ty;
}				t_text;

typedef struct s_map
{
	int			*map;
	int			sizeline;
	int			nbline;
	int			px;
	int			py;
	int			mapsur;
	int			other;
	int			error;
	char		name[BUFFER_SIZE];
	char		tex_no[BUFFER_SIZE];
	char		tex_so[BUFFER_SIZE];
	char		tex_we[BUFFER_SIZE];
	char		tex_ea[BUFFER_SIZE];
	int			flo;
	int			cel;
	int			fd;
	int			reduc;
}				t_map;

typedef struct s_admin
{
	t_map		*map;
	t_mlx		*mlx;
	t_player	*player;
	t_rays		*rays;
	t_text		*text;
}				t_admin;

/*--------------------GRAPHICAL PART----------------------*/

//--rendu affichage--//

void	draw_floor(t_admin *admin);
void	black_image(t_admin *admin);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		render(t_admin *admin);

//--rendu affichage texture -- //

int		find_color(t_text *text, char d);
void	choose_text(t_admin *admin, t_rays *rays);

//--rendu affichage minimap----//

void	size_minimap(t_map *map);
void	color_cube(t_mlx *mlx, t_map *map, int color);
void	drawmap2d(t_mlx *mlx, t_map *map);
void	drawplayer(t_admin *admin, t_mlx *mlx, t_player *player);

//--rayon 3D---//

void	get_dist_hv(t_player *player, t_rays *rays, int order);
double	get_dist(double px, double py, double hvx, double hvy);
void	choosedistfinal(t_admin *admin);
void	draw_wall(t_admin *admin, t_mlx *mlx);

void	rays_distcheck(t_player *player, t_rays *rays, t_map *map, int order);
void	rays_horizontalcheck(t_player *player, t_rays *rays);
void	rays_verticalcheck(t_player *player, t_rays *rays);
void	drawrays3d(t_admin *admin, t_player *player, t_rays *rays, t_map *map);

//---Interpretation keyboard---//

void	turn_right(t_player *player);
void	turn_left(t_player *player);
void	move_right(t_map *map, t_player *player);
void	move_left(t_map *map, t_player *player);
void	move_up(t_map *map, t_player *player);
void	move_down(t_map *map, t_player *player);

int		key_pressed(int keycode, t_admin *admin);
int		key_released(int keycode, t_admin *admin);
void	use_key(t_admin *admin);

//--manipulation du tableau int - MAP ----//

int		get_int(int x, int y, t_map *map);
int		get_coord(int x, t_map *map);

//--launch-----//

int		main(void);
void	init_struct(t_admin *admin);
int		mlx_start_init(t_mlx *mlx, t_admin *admin);
int		init_texture(t_mlx *mlx, t_text *text);
void	init_player_position(t_map *map, t_player *player, t_rays *rays);

//--close------//

int		ft_closeok(t_admin *admin);
int		ft_close(t_admin *admin);

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

#endif /* !CUB3D_H */

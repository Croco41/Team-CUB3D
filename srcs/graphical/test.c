#include "test.h"

// void drawRays3D(t_admin *admin, t_player *player, t_rays *rays, t_map *map)
// {
// 	//int r, mx, my, mp, dof;
// 	//double rx, ry, ra, xo, yo;
// 	rays->ra = player->pa - (5 * PI / 180);
// 	admin->rays->r = 0;
// 	while (rays->r < 1)
// 	{
// 	//Check horizontal Line
// printf(RED"pa = [%f] | ra = [%f]"RESET"\n", player->pa * 180 / PI, rays->ra * 180 / PI);
// 		rays->dof = 0;
// 		rays->distH = 1000000;
// 		rays->hx = player->px;
// 		rays->hy = player->py;
// 		double aTan = -1/(tan(rays->ra));
// 		//looking down
// 		if (rays->ra > PI)
// 		{
// 			rays->ry = (((int)player->py>>6)<<6) - 0.0001; //s'assurer qu'on soit en float et decalage de 6 bits 
// 			rays->rx = (player->py - rays->ry)*aTan + player->px;
// 			rays->yo = -64;
// 			rays->xo = -rays->yo*aTan;
// 		}
// 		//looking up
// 		else if (rays->ra < PI)
// 		{
// 			rays->ry = (((int)player->py>>6)<<6) + 64;
// 			rays->rx = (player->py - rays->ry)*aTan + player->px;
// 	//printf(BLUE"rays->rx: %f, rays->ry: %f, {player->py} : %d "RESET"\n", (rays->rx), rays->ry, player->py);
// 			rays->yo = 64;
// 			rays->xo = -rays->yo*aTan;
// 		}
// 		//looking straight left or right
// 		else if (rays->ra == 0 || rays->ra == PI)
// 		{
// 			rays->rx = player->px;
// 			rays->ry = player->py;
// 			rays->dof = 8; 
// 		}
// 		// else if (map->map[rays->mp] == 5)
// 		// 	exit (1);
// 	//printf(YELLOW"rays->rx: %f, {player->px} : %d "RESET"\n", (rays->rx), player->px);
// 		while (rays->dof < 8)
// 		{
// //printf("hello1\n");
// 			rays->mx = (int)(rays->rx) >> 6;
// 			rays->my = (int)(rays->ry) >> 6;
// 			rays->mp = rays->my * map->sizeline + rays->mx;
// 	//printf(YELLOW"rays->mp: %d, {rays->mx} : %d "RESET"\n", (rays->mp), rays->mx);
// 			if (rays->mp > 0 && rays->mp < map->mapS && map->map[rays->mp] == 1)
// 			{
// 				rays->hx = rays->rx;
// 				rays->hy = rays->ry;
// 				rays->distH = get_dist(player->px, player->py, rays->hx, rays->hy); //hit wall
// 				rays->dof = 8;
// 			}
// 			else
// 			{
// 				rays->rx += rays->xo;
// 				rays->ry += rays->yo; 
// 				rays->dof += 1; // next line
// 			}
// 	printf(BLUE"rays->rx: %f, rays->ry: %f, rays->dof: %d "RESET"\n", (rays->rx), rays->ry, rays->dof);

// 		}
// 		//drawLine(admin, admin->mlx);
// 		rays->ra = rays->ra + (PI / 180);
// 		rays->r++;
// 	}
// //printf("hello\n");
// }

// void drawRays3DVerti(t_admin *admin, t_player *player, t_rays *rays, t_map *map)
// {
// 	//int r, mx, my, mp, dof;
// 	//double rx, ry, ra, xo, yo;
// 	rays->ra = player->pa - (5 * PI / 180);
// 	rays->r = 0;
// 	while (rays->r < 1)
// 	{
// 	//Check horizontal Line
// printf(RED"pa = [%f] | ra = [%f]"RESET"\n", player->pa * 180 / PI, rays->ra * 180 / PI);
// 		rays->dof = 0;
// 		rays->distV = 1000000;
// 		rays->vx = player->px;
// 		rays->vy = player->py;
// 		double nTan = -(tan(rays->ra));
// 		//looking left
// 		if (rays->ra > PI/2 && rays->ra < (3 * PI)/2)
// 		{
// 			rays->rx = (((int)player->px>>6)<<6) - 0.0001; //s'assurer qu'on soit en float et decalage de 6 bits 
// 			rays->ry = (player->px - rays->rx)*nTan + player->py;
// 			rays->xo = -64;
// 			rays->yo = -rays->xo*nTan;
// 		}
// 		//looking right
// 		else if (rays->ra < PI/2 || rays->ra > (3 * PI)/2)
// 		{
// 			rays->rx = (((int)player->px>>6)<<6) + 64;
// 			rays->ry = (player->px - rays->rx)*nTan + player->py;
// 	//printf(BLUE"rays->rx: %f, rays->ry: %f, {player->py} : %d "RESET"\n", (rays->rx), rays->ry, player->py);
// 			rays->xo = 64;
// 			rays->yo = -rays->xo*nTan;
// 		}
// 		//looking straight up or down
// 		else if (rays->ra == 0 || rays->ra == PI)
// 		{
// 			rays->rx = player->px;
// 			rays->ry = player->py;
// 			rays->dof = 8; 
// 		}
// 		// else if (map->map[rays->mp] == 5)
// 		// 	exit (1);
// 	//printf(YELLOW"rays->rx: %f, {player->px} : %d "RESET"\n", (rays->rx), player->px);
// 		while (rays->dof < 8)
// 		{
// //printf("hello1\n");
// 			rays->mx = (int)(rays->rx) >> 6;
// 			rays->my = (int)(rays->ry) >> 6;
// 			rays->mp = rays->my * map->sizeline + rays->mx;
// 	//printf(YELLOW"rays->mp: %d, {rays->mx} : %d "RESET"\n", (rays->mp), rays->mx);
// 			if (rays->mp > 0 && rays->mp < map->mapS && map->map[rays->mp] == 1)
// 			{
// 				rays->vx = rays->rx;
// 				rays->vy = rays->ry;
// 				rays->distV = get_dist(player->px, player->py, rays->vx, rays->vy); //hit wall
// 				rays->dof = 8;
// 			}
// 			else
// 			{
// 				rays->rx += rays->xo;
// 				rays->ry += rays->yo; // hit wall
// 				rays->dof += 1; // next line
// 			}
// 	printf(BLUE"rays->rx: %f, rays->ry: %f, rays->dof: %d "RESET"\n", (rays->rx), rays->ry, rays->dof);

// 		}
// 		// if (rays->distV < rays->distH)
// 		// {
// 		// 	rays->rx = rays->vx;
// 		// 	rays->ry = rays->vy;
// 		// }
// 		// if (rays->distH < rays->distV)
// 		// {
// 		// 	rays->rx = rays->hx;
// 		// 	rays->ry = rays->hy;
// 		// }
// 		drawLine(admin, admin->mlx);
// 		rays->ra = rays->ra + (PI / 180);
// 		rays->r++;
// 	}
// //printf("hello\n");
// }

// double	get_dist(double px, double py, double hx, double hy)
// {

// 	return (sqrt((hx - px) * (hx - px) + (hy - py) * (hy - py)));	
// }

// int 	get_int(int x, int y, t_map *map)
// {
// 	if (y == 0)
// 		return (x);
// 	else if (y > 0 && y < map->nbline && x < map->sizeline)
// 	{
// 		return ((y * map->sizeline) + x);
// 	}
// 	else
// 	{
// 		printf("Erreur de coordonnees");
// 		return (-1);
// 	}
// }

// int 	get_coord(int x, t_map *map)
// {
// 	if (x < 0 || x > map->mapS)
// 	{
// 		map->px = -1;
// 		map->py = -1;
// 		printf("Erreur de coordonnees");
// 		return (-1);
// 	}
// 	else if (x < map->sizeline)
// 	{
// 		map->px = x;
// 		map->py = 0;
// 	}
// 	else if (x >= map->sizeline && x < map->mapS)
// 	{
// 		map->py = x / map->sizeline;
// 		map->px = x - (map->py * map->sizeline);
// 	}
// 	return (0);
// }


// void	color_cube(t_mlx *mlx, t_map *map, int color)
// {

// 	map->px *= map->mapS;
// 	map->py *= map->mapS;
// 	int i;
// 	int j;

// 	i = map->mapS - 1;
// 	j = 0;

// 	while (j < map->mapS - 1)
// 	{
// 		while (i > 0)
// 		{
// 			//printf("checkpixel\n");
// 			my_mlx_pixel_put(mlx, map->px + i, map->py + j, color);
// 			i--;
// 		}
// 		i = map->mapS - 1;
// 		j++;
// 	}
// }

// void	drawMap2D(t_mlx *mlx, t_map *map)
// {
// 	int x; 

// 	x = 0;

// 	while (x < 64)
// 	{
// 		if (map->map[x] == 1)
// 		{
// 			if (get_coord(x, map) == 0)
// 				color_cube(mlx, map, WHITE_PIXEL);	
// 		}
// 		else if (map->map[x] == 0)
// 		{
// 			if (get_coord(x, map) == 0)
// 				color_cube(mlx, map, GRAY_PIXEL);	
// 		}
// //printf(YELLOW"map->map[x]: %d, [x]: %d "RESET"\n", (map->map)[x], x);
// 		x++;
// 	}
// }


// printf(RED"map->map[i]: %d, [i]: %d "RESET"\n", (map->map)[i], i);

// // printf(BLUE"t: %d | [y*map+x]: %d"RESET"\n", t, (y * map->sizeline + x));				
// // printf(RED"map->map[t]: %d | map->map[y*map+x]: %d"RESET"\n", map->map[t], map->map[y * map->sizeline + x]);

// // printf(YELLOW"t: %d | [y*map+x]: %d"RESET"\n", t, (y * map->sizeline + x));				
// // printf(GREEN"map->map[t]: %d | map->map[y*map+x]: %d"RESET"\n", map->map[t], map->map[y * map->sizeline + x]);




// int	ft_readkey(int keycode, t_admin *admin)
// {

// 	printf(RED"ICIREADKEY [pa] %f"RESET"\n", admin->player->pa);
// 	if (keycode == 97) //a
// 	{
// 		//printf(RED"ICI 97"RESET"\n");
// 		//admin->player->px -= 15;
// 		admin->player->pa-=0.1;
		
// 		if (admin->player->pa < 0)
// 			admin->player->pa += 2*PI;
// 		admin->player->pdx = cos(admin->player->pa) * 5;
// 		admin->player->pdy = sin(admin->player->pa) * 5;
// 		// admin->player->px += admin->player->pdy;
// 		// admin->player->py -= admin->player->pdx;
// 	}
// 	if (keycode == 100)  //d
// 	{
// 		//admin->player->px += 15;
// 		admin->player->pa+=0.1;
// 		if (admin->player->pa > 2*PI)
// 			admin->player->pa -= 2*PI;
// 		admin->player->pdx = cos(admin->player->pa) * 5;
// 		admin->player->pdy = sin(admin->player->pa) * 5;
// 		// admin->player->px -= admin->player->pdy;
// 		// admin->player->py += admin->player->pdx;
// 	}

// 	int	next_x;
// 	int next_y;

// 	if (keycode == 119)
// 	{
// 		next_x = ((admin->player->px + admin->player->pdx) / admin->map->mapS);
// 		next_y = ((admin->player->py + admin->player->pdy) / admin->map->mapS);
// 		//admin->player->pa
// 		printf(GREEN"ICIW119 [pdx] %f | [pdy] %f "RESET"\n", admin->player->pdx, admin->player->pdy);
// 		if (admin->map->map[get_int(next_x, (admin->player->py / admin->map->mapS), admin->map)] == 0)
// 			admin->player->px += admin->player->pdx;
// 		if (admin->map->map[get_int((admin->player->px / admin->map->mapS), next_y, admin->map)] == 0)
// 			admin->player->py += admin->player->pdy;
// 	}

// 	if (keycode == 115) 
// 	{
// 		next_x = ((admin->player->px - admin->player->pdx) / admin->map->mapS);
// 		next_y = ((admin->player->py - admin->player->pdy) / admin->map->mapS);
// 		//admin->player->py += 15;
// 		if (admin->map->map[get_int(next_x, (admin->player->py / admin->map->mapS), admin->map)] == 0)
// 			admin->player->px -= admin->player->pdx;
// 		if (admin->map->map[get_int((admin->player->px / admin->map->mapS), next_y, admin->map)] == 0)
// 			admin->player->py -= admin->player->pdy;
// 	}
// 	// if (keycode == 65307)
// 	// {
// 	// 	ft_closeok(admin);
// 	// 	return (0);
// 	// }
	
// 	//print_img(&admin->map, admin);
// 	// return (1);
// 	return (0);
// }

// void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
// {
// //printf(YELLOW"img->width = %d | x = %d | y = %d"RESET"\n", mlx->window->width, x, y);
// // printf(RED"x = %d | y = %d"RESET"\n", x, y);
// 	((int *)mlx->imgame->data)[y * mlx->imgame->width + x] = color;
// }


// void black_image(t_admin *admin)
// {
// 	int i; 
// 	int j;

// 	j = 0;
// 	i = 0;
// //printf("Hello %d | j %d\n", i , j);
// 	while (j < W_HEIGHT)
// 	{
// 		while (i < W_WIDTH)
// 		{
// 			//printf("Hello %d | j %d\n", i , j);
// 			my_mlx_pixel_put(admin->mlx, i, j, 0x000000);
// 			i++;
// 		}
// 		j++;
// 		i = 0;
// 	}
// }

// void drawPlayer(t_admin *admin, t_mlx *mlx)
// {
// //printf(GREEN"player->px = %d | player->py = %d | adresse player= %p"RESET"\n", admin->player->px, admin->player->py, admin->player );
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;

// 	while (y < 5)
// 	{
// 		while (x < 5)
// 		{
// 			my_mlx_pixel_put(mlx, admin->player->px + x, admin->player->py + y, 0xFFFF66);
// 			x++;		
// 		}
// 		y++;
// 		x = 0;
// 	}
// 	//drawLine(admin, mlx);
// 	drawRays3D(admin, admin->player, admin->rays, admin->map);
// 	drawRays3DVerti(admin, admin->player, admin->rays, admin->map);
// 	//drawLine(admin, mlx);
// }

// void drawLine(t_admin *admin, t_mlx *mlx)
// {
// //printf(GREEN"player->px = %d | player->py = %d | adresse player= %p"RESET"\n", admin->player->px, admin->player->py, admin->player );
// 	double	x;
// 	double	dist;
// 	double	finalx;
// 	double	finaly;

// 	x = 0;

// 	if (admin->rays->distV < admin->rays->distH)
// 		{
// 			admin->rays->rx = admin->rays->vx;
// 			admin->rays->ry = admin->rays->vy;
// 		}
// 	else if (admin->rays->distH < admin->rays->distV)
// 		{
// 			admin->rays->rx = admin->rays->hx;
// 			admin->rays->ry = admin->rays->hy;
// 		}
	
// 	dist = sqrt((admin->rays->rx - admin->player->px) * (admin->rays->rx - admin->player->px) + (admin->rays->ry - admin->player->py) * (admin->rays->ry - admin->player->py));

// 	while (x < 100)
// 	{
// 		// dist = admin->player->px + (cos(admin->rays->ra) * x * (admin->rays->rx /100));
// 		finalx = admin->player->px + (cos(admin->rays->ra) * x * (dist /100));
// 		finaly = admin->player->py + (sin(admin->rays->ra) * x * (dist /100));
// 		//my_mlx_pixel_put(mlx, admin->player->px + admin->player->pdx*x , admin->player->py + admin->player->pdy*x, GREEN_PIXEL);
// 		// my_mlx_pixel_put(mlx, admin->player->px + admin->rays->rx*x , admin->player->py + admin->rays->ry*x, GREEN_PIXEL);
// 		if (admin->player->px < admin->map->sizeline * 64 && admin->player->py < admin->map->nbline * 64)
// 			//my_mlx_pixel_put(mlx, dist, admin->player->py, GREEN_PIXEL);
// 			my_mlx_pixel_put(mlx, finalx, finaly, GREEN_PIXEL);
			

// 		x++;
// 	}
// }



// int	render(t_admin *admin)
// {
// //printf(CYAN"Render:adresse mlx= %p"RESET"\n", admin->mlx );

// 	if (admin->mlx->mlx_win == NULL)
// 	{
// 		printf(YELLOW"admin->mlx = %p"RESET"\n", admin->mlx);
// 		exit (1);
// 	}
// //printf(RED"REnder:player->px = %d | player->py = %d | adresse player= %p"RESET"\n", admin->player->px, admin->player->py, admin->player );
// 	black_image(admin);
	
// 	drawMap2D(admin->mlx, admin->map);
	
// 	drawPlayer(admin, admin->mlx);
// 	mlx_put_image_to_window(admin->mlx->mlx_ptr, admin->mlx->mlx_win, admin->mlx->imgame, 0, 0);
// 	return (0);
// }



// void	init_struct(t_admin *admin)
// {
// 	admin->map.map = NULL;
// 	admin->map.nbcollecti = 0;
// 	admin->map.nbexit = 0;
// 	admin->map.nbplayer = 0;
// 	admin->map.other = 0;
// 	admin->map.error = 0;
// 	admin->map.nbline = 0;
// 	admin->map.player.move = 0;
// 	admin->map.player.x = 0;
// 	admin->map.player.y = 0;
// 	admin->mlx.mlx_ptr = NULL;
// 	admin->mlx.mlx_win = NULL;
// 	admin->mlx.window = NULL;
// 	//init_mlx(&admin->mlx);
// }

// int	mlx_start_init(t_mlx *mlx, t_admin *admin)
// {
	
// 	mlx->mlx_ptr = mlx_init();
// 	if (!mlx->mlx_ptr)
// 		return (1);
// 	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, W_WIDTH, W_HEIGHT, "Hello World");
// // printf(RED"mlx = %p"RESET"\n", mlx);
// // printf(GREEN"admin->mlx = %p"RESET"\n", &admin->mlx);

// 	if (mlx->mlx_win == NULL)
// 	{
// // printf(GREEN"LA"RESET"\n");
// 		return (1);
// 	}
// 	mlx->imgame = mlx_new_image(mlx->mlx_ptr, W_WIDTH, W_HEIGHT);
// // printf(CYAN"img_width = %d | img_height = %d"RESET"\n", mlx->window->width, mlx->window->height);
// 	if (mlx->imgame == NULL)
// 	{
// //printf(YELLOW"LA"RESET"\n");
// 		return (2);
// 	}

// //printf(YELLOW"Mlx_start_init:player->px = %d | player->py = %d | adresse player= %p"RESET"\n", admin->player->px, admin->player->py, admin->player );
// //printf(CYAN"mlx_start_init:adresse mlx= %p"RESET"\n", admin->mlx );

// 	mlx_loop_hook(mlx->mlx_ptr, &render, admin);

// 	mlx_key_hook(admin->mlx->mlx_win, ft_readkey, admin);

// 	mlx_loop(mlx->mlx_ptr);

// 	mlx_destroy_image(mlx->mlx_ptr, mlx->imgame);
// 	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
// 	mlx_destroy_display(mlx->mlx_ptr);

// 	return (0);
// }

// void	init_struct(t_admin *admin)
// {
// 	//admin->map->map = ;
// 	admin->map->nbexit = 0;	
// 	admin->map->other = 0;
// 	admin->map->error = 0;
// 	admin->map->nbline = 0;
// 	admin->map->px = -1;
// 	admin->map->py = -1;
// 	admin->player->move = 0;
// 	admin->player->x = 0;
// 	admin->player->y = 0;
// 	admin->player->px = 300;
// 	admin->player->py = 300;
// 	admin->player->pa = PI/2;
// 	admin->player->pdx = cos(admin->player->pa) * 5;
// 	admin->player->pdy = sin(admin->player->pa) * 5;
// ///printf(BLUE"INITSTRUC:player->px = %d | player->py = %d | adresse player= %p"RESET"\n", admin->player->px, admin->player->py, admin->player );

// 	admin->mlx->mlx_ptr = NULL;
// 	admin->mlx->mlx_win = NULL;
// 	admin->mlx->imgame = NULL;
// 	admin->rays->dof = 0;
// 	admin->rays->mp = 0;
// 	admin->rays->mx = 0;
// 	admin->rays->my = 0;
// 	admin->rays->r = 0;
// 	admin->rays->rx = 0;
// 	admin->rays->ry = 0;
// 	admin->rays->ra = 0;
// 	admin->rays->xo = 0;
// 	admin->rays->yo = 0;
// 	//init_mlx(&admin->mlx);
// }

// int	main(void)
// {
// 	t_admin admin;
// 	t_map map;
// 	t_mlx mlx;
// 	t_player player;
// 	t_rays rays;
	
// 	admin.map = &map;
// 	admin.mlx = &mlx;
// 	admin.player = &player;
// 	admin.rays = &rays;
// 	init_struct(&admin);

// 	admin.map->sizeline = 8;
// 	admin.map->nbline = 8;
// 	admin.map->mapS = 64;
// 	int map2[] =
// 	{
// 		1,1,1,1,1,1,1,1,    
// 		1,0,1,0,0,0,0,1,    
// 		1,0,1,0,0,0,0,1,
// 		1,0,1,0,0,0,0,1,
// 		1,0,0,0,0,0,0,1,
// 		1,0,0,0,0,1,0,1,
// 		1,0,0,0,0,0,0,1,
// 		1,1,1,1,1,1,1,1,
// 	};
// 	admin.map->map = map2;
// 	if (!mlx_start_init(admin.mlx, &admin))
// 	{
// 		return (1);
// 	}
// 	return (0);
// }


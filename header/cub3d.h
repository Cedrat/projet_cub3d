/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 01:29:46 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/18 23:09:19 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <X11/keysymdef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_dda
{
	int		mapx;
	int		mapy;
	double	disttoy;
	double	disttox;
	double	posrayx;
	double	posrayy;
	double	nextwallx;
	double	nextwally;
	double	dir_x;
	double	dir_y;
	double	tan_angle;
}				t_dda;

typedef struct	s_wall
{
	void	*img;
	void	*img_addr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	int		**color_tab;
}				t_wall;

typedef struct	s_textures
{
	int		f;
	int		c;
	t_wall	*e;
	t_wall	*n;
	t_wall	*w;
	t_wall	*s;
	t_wall	*sp;
}				t_textures;

typedef struct	s_draw_sprites
{
	int		nb_sprite;
	int		sp_h;
	int		x_start;
	int		x_end;
	int		y_start;
	int		y_end;
	int		old_start_y;
	int		old_start_x;
	double	perp_dist;
	double	angle_sp;
	double	*sp_x;
	double	*sp_y;
	double	*dist_to_p;
}				t_draw_sp;

typedef struct	s_security
{
	int floor;
	int ceil;
	int res;
	int tex_n;
	int tex_s;
	int tex_e;
	int tex_w;
	int tex_sp;
	int	map;
}				t_secu;

typedef struct	s_img
{
	char		side;
	int			map_x;
	int			map_y;
	int			res_x;
	int			res_y;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			save;
	void		*mlx_ptr;
	void		*mlx_wd;
	void		*img;
	void		*img_addr;
	char		**map;
	double		ratio;
	double		angle_start;
	double		angle_view;
	double		pos_x;
	double		pos_y;
	double		vect_x;
	double		vect_y;
	double		perpdist;
	double		raydir_x;
	double		raydir_y;
	double		*z_buffer;
	size_t		map_width;
	size_t		map_heigth;
	t_secu		*secu;
	t_textures	*skin;
	t_draw_sp	*draw_sp;
	t_dda		*dda;
}				t_img;

int				return_free(void *ptr);
void			loop_ig(t_img *img);
void			create_c_f(char side, t_img *param, unsigned int rgb_c);
void			quick_quit(t_img *img);
void			ft_free_tex(t_img *img);
void			write_pixel(int fd, unsigned int color);
int				check_secu_tex(t_img *param, char face);
size_t			ft_is_nb(size_t i, char *file);
void			mlx_del(void *mlx_ptr);
void			ft_free_map(t_img *img);
void			ft_free_textures(t_img *img, t_wall *skin);
void			ft_write_img(int fd, t_img *img);
void			ft_write_pic_header(int fd, t_img *img);
void			ft_write_header(int fd, t_img *img);
int				ft_screen(t_img *img);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_init_secu(t_secu *secu);
int				quit(t_img *img);
int				ft_is_rgb(char *file);
int				ft_is_res(char *line);
int				ft_is_cub(char *file);
void			ft_block(t_img *img, double new_pos_x, double new_pos_y);
int				ft_init_s_sp(t_draw_sp *dsp);
void			ft_draw_sp(t_img *img, int x, int y, size_t i);
void			init_t_dda(double angle, t_img *img, t_dda *dda);
void			nb_print_sp(t_img *img, t_draw_sp *dsp);
int				is_view(t_img *img, t_draw_sp *dsp);
void			nb_view_sprite(t_img *img, t_draw_sp *dsp);
double			ft_distance(char **map, double angle, t_img *img, t_dda *dda);
void			draw_sprite(t_img *img, t_draw_sp *dsp);
int				ft_put_sp_xy(t_img *param, t_draw_sp *dsp);
int				ft_count_sp(t_img *param);
void			ft_calcul_for_sp(t_draw_sp *dsp, t_img *img);
int				ft_sp(t_img *img, int h, int x, int *y);
void			ft_create_sprite(t_draw_sp *dsp, int pixel, t_img *img);
double			ft_floatypart(double a);
void			ft_wall_n(t_img *img, int h, int x, int *y);
void			ft_wall_e(t_img *img, int h, int x, int *y);
void			ft_wall_w(t_img *img, int h, int x, int *y);
void			ft_wall_s(t_img *img, int h, int x, int *y);
void			ft_who_side(t_img *param, int side);
int				keycode(int keycode, t_img *img);
int				keycode2(int keycode, t_img *img);
int				until_next_wall(t_img *param, int step_x, int step_y);
int				ft_view(t_img *param, t_draw_sp *dsp);
void			ft_mlx_pixel_put(t_img *data, int x, int y, int color);
void			ft_create_wall(double dist_wall, int pixel, t_img *img);
double			ft_abs(double a);
double			ft_distance_to_wall(t_img *param, double screenx);
int				ft_extract_map(t_img *param, char *map);
int				ft_convert_map(char *map, t_img *param);
int				ft_pos_and_angle(size_t heigth, size_t width,
											t_img *param, char cardinal);
void			ft_convert_map_utils(size_t *w, size_t *i, char *a, char *b);
int				ft_ispos(int ok, char face);
int				ft_initial(int *ok, size_t *h, size_t *w);
int				ft_verif(char map, int *ok);
void			ft_initialize_data(size_t *nbr_flags, int *ok,
														size_t *h, size_t *w);
int				ft_verif_map_h(t_img *param);
int				ft_verif_map_w(t_img *param);
int				**ft_color_tab(t_wall *face);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_err_code(int i);
int				ft_err_code_2(int i);
int				ft_putstr(char *str);
int				ft_extract_color(char *line, t_img *param, char fc);
int				ft_create_img(t_img *param, char *temp, char face);
int				ft_create_img2(t_img *param, char *temp, char face);
int				ft_extract_data(t_img *param, char *line);
int				ft_extract_data_next(t_img *param, char *line, int i);
int				ft_extract_reso(char *line, t_img *param);
int				ft_parsing(char *pathname, t_img *param);
int				ft_while_parsing(int fd, char **map, t_img *param);
int				ft_while_while_parsing(int fd, char *line,
											char **map, int *ret);
size_t			ft_strlen(const char *s);
char			*ft_strjoin_f(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strchr(const char *s, int c);
int				get_next_line(int fd, char **line);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_extract_img(t_img *param, char *line, char face);
char			*ft_path_extract(char *line);
int				ft_atoi(const char *str);
int				ft_create_rgb(int r, int g, int b);
t_img			*ft_init_s_img(void);
void			ft_dist_to_p(t_draw_sp *dsp, double pos_x, double pos_y);
void			ft_quicksort(t_draw_sp *dsp);
char			wall_side(double dir_x, double dir_y,
							double dist_to_x, double dist_to_y);
double			ft_next_intersect(double direction, int map, double player_pos);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 02:49:06 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/24 19:40:50 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define EXT ".ber"
# define CHAREST "01CEP"

# define WALL "./img/plottrait.xpm"
# define P "./img/benzefondver.xpm"
# define GROUND "./img/sol.xpm"
# define EXIT "./img/lacage.xpm"
# define COLLECT "./img/ballondor.xpm"
# define CO "./img/colone.xpm"
# define COINHG "./img/coinhg.xpm"
# define COINBG "./img/coinbag.xpm"
# define COINHD "./img/coinhd.xpm"
# define COINBD "./img/coinbd.xpm"

typedef struct s_position
{
	int			x;
	int			y;
	int			py;
	int			px;
	int			ey;
	int			ex;
	int			yvirus;
	int			xvirus;
	int			isnewpath;
	char		**map;
	char		**mapcpy;
}				t_position;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*mlx_win;
	void		*imgblock[256];
	t_position	*ptrmapstruct;
	int			countmouv;
	int			test;
}				t_data;

void			bigtab_cpy(char ***str, char **src, t_position data);
void			display(char **map);
int				check_toutes_erreurs(const char *argv, t_position *data);
int				ft_covid(t_position *data);
void			ft_propagation(int y, int x, t_position *data);
void			ft_virus_row(t_position *data, int y, int x, int direction);
void			ft_virus_col(t_position *data, int y, int x, int direction);
int				clean_tab(char **str);
int				mapcheck(char **tab, t_position *pos);
int				is_e(char **map, char c);
int				check_pe(char **tab, char c);
void			get_pos(char **map, t_position *pos);
int				is_incharset(char c, char *charset);
int				ft_strlen_double(char **str);
char			**readfile(int fd);
int				empty_line(char *str);
int				check_ext(const char *file);
int				init_mlx(t_data *img, t_position *map);

void			display_pix(t_data *img, t_position *map);

int				next_position_col(t_data *img, int *i, int *y, int dir);
int				next_position_row(t_data *img, int *i, int *y, int dir);
int				deal_key(int key, t_data *img);
void			split_img(t_data *img, t_position *map, int i, int j);
int				raschakal(t_data *param);
void			display_pix(t_data *img, t_position *map);
int				ft_destroy(t_data *img, int j);
int				set_img(t_data *img);

int				ft_graphical(t_data *img, t_position *map);
int				ft_goal(t_data *img);
void			display_pix2(t_data *img, t_position *map, int *i, int *j);

#endif

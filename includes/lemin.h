/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 09:00:11 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/08 09:02:12 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "ft_printf/includes/ft_printf.h"
# include "ft_printf/includes/get_next_line.h"

typedef struct		s_point
{
	int				x;
	int				y;

}					t_point;

typedef struct		s_lroom
{
	char			*name;
	bool			last;
	size_t			ants;
	size_t			distance;
	t_point			coo;
	size_t			neighborsnb;
	struct s_lroom	**neighbors;
	struct s_lroom	*next;
	struct s_lroom	*previous;

}					t_lroom;

typedef struct		s_ant
{
	size_t			ant;
	size_t			moves;
	t_lroom			*room;
	struct s_ant	*next;

}					t_ant;

typedef struct		s_lemenv
{
	bool			colors;
	bool			total;
	bool			dispmap;
	bool			regdispmap;
	bool			followall;
	size_t			moves;
	size_t			ants;
	size_t			follow;
	size_t			roomsnb;
	t_lroom			*start;
	t_lroom			*end;
	t_lroom			**rooms;
	t_ant			*antity;
	bool			endreached;
	char			*strmap;
}					t_lemenv;

void				ft_freeenv(t_lemenv *env);
void				ft_dispmove(t_lemenv *env, t_lroom *tmp, t_ant *ant);
void				ft_dispmap(t_lemenv *env, t_ant *ant);
void				ft_addneighbors(t_lroom *a, t_lroom *b);
void				ft_addtube(t_lemenv *env, char *str);
void				ft_pushroom(t_lemenv *env, t_lroom *room);
t_lroom				*ft_getroom(char *str, t_lemenv *env, bool tube);
void				ft_getlemmap(t_lemenv *env);
bool				ft_setdist(t_lemenv *env, t_lroom *tmp, size_t dist);
void				ft_antspawn(t_lemenv *env);
t_lroom				*ft_checkneighboors(t_lemenv *env, t_ant *ant);
bool				ft_moveant(t_lemenv *env, t_ant *ant);
void				ft_solvelemmap(t_lemenv *env);
void				ft_error(t_lemenv *env, char *str, char *str2, bool fatal);
void				ft_lemkeepmap(t_lemenv *env, char *str);
void				ft_checkrooms(t_lemenv *env, size_t room);
void				ft_freeants(t_lemenv *env);

#endif

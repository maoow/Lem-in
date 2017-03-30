/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:47:32 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/30 17:16:43 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/includes/ft_printf.h"
#include "ft_printf/includes/get_next_line.h"

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
	t_lroom			*room;
	struct s_ant	*next;

}					t_ant;
typedef struct		s_lemenv
{
	bool			colors;
	bool			total;
	bool			dispmap;
	size_t			moves;
	size_t			ants;
	size_t			roomsnb;
	t_lroom			*start;
	t_lroom			*end;
	t_lroom			**rooms;
	t_ant			*antity;
	bool			endreached;
}					t_lemenv;


void		ft_solvelemmap(t_lemenv *env);
void		ft_error(char *str, char *str2);

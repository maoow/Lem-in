/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemgetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 10:29:02 by cbinet            #+#    #+#             */
/*   Updated: 2017/05/12 15:39:24 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Lem-in.h"

void		ft_freeroom(t_lroom **room)
{
	free((*room)->name);
	free((*room)->neighbors);
	free(*room);
	*room = NULL;
}

void		ft_freeenv(t_lemenv *env)
{
	size_t		i;
	t_ant		*tmp;

	i = 0;
	while (i < env->roomsnb)
	{
		ft_freeroom(&(env->rooms[i]));
		i++;
	}
	free(env->rooms);
	while (env->antity)
	{
		tmp = env->antity->next;
		free(env->antity);
		env->antity = tmp;
	}
}

void		ft_addneighbors(t_lroom *a, t_lroom *b)
{
	size_t		i;
	t_lroom		**tmproom;

	i = 0;
	tmproom = (t_lroom **)malloc(sizeof(t_lroom *) * (a->neighborsnb + 1));
	while (++i <= a->neighborsnb)
		tmproom[i - 1] = a->neighbors[i - 1];
	tmproom[i - 1] = b;
	if (a->neighborsnb != 0)
		free(a->neighbors);
	a->neighbors = tmproom;
	i = 0;
	tmproom = (t_lroom **)malloc(sizeof(t_lroom *) * (b->neighborsnb + 1));
	while (++i <= b->neighborsnb)
		tmproom[i - 1] = b->neighbors[i - 1];
	tmproom[i - 1] = a;
	if (b->neighborsnb != 0)
		free(b->neighbors);
	b->neighbors = tmproom;
	a->neighborsnb++;
	b->neighborsnb++;
}

void		ft_addtube(t_lemenv *env, char *str)
{
	char			*tmp;
	t_lroom			*tmproom;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '-')
		i++;
	tmp = ft_strsub(str, 0, i);
	while (j < env->roomsnb && ft_strcmp(env->rooms[j]->name, tmp))
		j++;
	if (j < env->roomsnb)
		tmproom = env->rooms[j];
	free(tmp);
	tmp = ft_strdup(str + i + 1);
	j = 0;
	while (j < env->roomsnb && ft_strcmp(env->rooms[j]->name, tmp))
		j++;
	if (j < env->roomsnb)
		ft_addneighbors(tmproom, env->rooms[j]);
	free(tmp);
	free(str);
}

void		ft_getlemmap(t_lemenv *env)
{
	char		*str;
	t_lroom		*room;
	bool		tube;

	tube = false;
	if (get_next_line(0, &str) && ft_strlen(str))
	{
	ft_lemkeepmap(env, str);
		if (ft_isdigit(str[0]))
			env->ants = ft_atoi(str);
		free(str);
	}
	if (env->ants == 0)
		ft_error(env, "No ants", "");
	while (get_next_line(0, &str))
	{
	ft_lemkeepmap(env, str);
		if (ft_strchr(str, '-'))
		{
			tube = true;
			ft_addtube(env, str);
		}
		else if ((room = ft_getroom(str, env, tube)))
			ft_pushroom(env, room);
	}
}

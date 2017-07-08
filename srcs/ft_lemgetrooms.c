/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemgetrooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 12:13:09 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/08 08:59:11 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			ft_pushroom(t_lemenv *env, t_lroom *room)
{
	t_lroom		**tmp;
	size_t		i;

	i = 0;
	env->roomsnb++;
	room->neighborsnb = 0;
	room->ants = 0;
	room->distance = 0;
	if (!(tmp = (t_lroom **)malloc(sizeof(t_lroom *) * env->roomsnb)))
		exit(1);
	while (i < env->roomsnb - 1)
	{
		tmp[i] = env->rooms[i];
		i++;
	}
	tmp[i] = room;
	if (env->rooms)
		free(env->rooms);
	env->rooms = tmp;
	ft_checkrooms(env, i);
}

void			ft_getroomcoo(t_lemenv *env, char *str, t_lroom *room)
{
	size_t		i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	room->name = ft_strsub(str, 0, i);
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	room->coo.x = ft_atoi(str + i);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	if (str[i])
		room->coo.y = ft_atoi(str + i);
	else
		ft_error(env, "incorrect room name/coordinates", "", true);
	room->ants = 0;
}

t_lroom			*ft_setroom(t_lemenv *env, t_lroom *room, bool start, bool end)
{
	if (start)
	{
		env->start = room;
		room->ants = env->ants;
	}
	if (end)
		env->end = room;
	room->last = end;
	return (room);
}

t_lroom			*ft_getroom(char *str, t_lemenv *env, bool tube)
{
	t_lroom		*room;
	bool		start;
	bool		end;

	start = false;
	end = false;
	while (str[0] == '#')
	{
		start = !ft_strcmp("##start", str);
		end = !ft_strcmp("##end", str);
		if (str && ft_strcmp("##start", str) && ft_strcmp("##end", str))
			return (NULL);
		free(str);
		get_next_line(0, &str);
		ft_lemkeepmap(env, str);
	}
	if (tube || str[0] == 'L' || ft_strchr(str, '-'))
		ft_error(env, "not well formated room/tube", str, true);
	else if ((room = (t_lroom*)malloc(sizeof(t_lroom))))
	{
		ft_getroomcoo(env, str, room);
		free(str);
		return (ft_setroom(env, room, start, end));
	}
	return (NULL);
}

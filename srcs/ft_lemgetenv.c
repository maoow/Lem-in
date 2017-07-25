/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemgetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 10:29:02 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/12 14:03:59 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		ft_freeroom(t_lroom **room)
{
	free((*room)->name);
	if ((*room)->neighborsnb)
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
	if (env->strmap)
		free(env->strmap);
}

static void	ft_readthrough(t_lemenv *env)
{
	char		*str;
	bool		tube;
	t_lroom		*room;

	tube = false;
	while (get_next_line(0, &str) && ft_strlen(str))
	{
		ft_lemkeepmap(env, str);
		if ((ft_strchr(str, '-') && !ft_strchr(str, ' ')) && str[0] != '#')
		{
			if (!env->end)
				ft_error(env, "setting a tube while no end set", true);
			else if (!env->start)
				ft_error(env, "setting a tube while no start set", true);
			tube = true;
			ft_addtube(env, str);
		}
		else if (!tube && (room = ft_getroom(str, env, tube)))
			ft_pushroom(env, room);
	}
}

void		ft_getlemmap(t_lemenv *env)
{
	char		*str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (get_next_line(0, &str) && ft_strlen(str))
	{
		ft_lemkeepmap(env, str);
		while (str[j] == '0')
			j++;
		while (str[i] && ft_isdigit(str[i]))
			i++;
		str[i] = '\0';
		if (i - j > 10 || (i - j == 10 && ft_strcmp("2147483647", str + j) < 0))
			ft_error(env, "ant quantity up to int max", true);
		env->ants = ft_atoi(str);
		free(str);
	}
	if (env->ants == 0)
		ft_error(env, "No ants or negative number of ants", true);
	ft_readthrough(env);
}

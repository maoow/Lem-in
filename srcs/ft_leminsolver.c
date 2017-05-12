/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leminsolver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:50:05 by cbinet            #+#    #+#             */
/*   Updated: 2017/05/12 15:48:54 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Lem-in.h"

bool		ft_setdist(t_lemenv *env, t_lroom *tmp, size_t dist)
{
	size_t		i;
	bool		usefull;

	usefull = false;
	i = 0;
	dist++;
	while (i < tmp->neighborsnb)
	{
		if (tmp->neighbors[i] == env->start)
		{
			env->endreached = true;
			usefull = true;
		}
		if ((tmp->neighbors[i]->distance == 0 && tmp->neighbors[i] != env->end))
		{
			tmp->neighbors[i]->distance = dist;
			if (ft_setdist(env, tmp->neighbors[i], dist))
				usefull = true;
		}
		i++;
	}
	if (!usefull)
		tmp->distance = INT_MAX;
	return (usefull);
}

t_lroom		*ft_checkneighboors(t_lemenv *env, t_ant *ant)
{
	size_t		i;
	size_t		distance;
	t_lroom		*tmp;

	tmp = NULL;
	distance = INT_MAX;
	i = 0;
	while (i < ant->room->neighborsnb)
	{
		if (ant->room->neighbors[i]->distance <= distance &&
				(ant->room->neighbors[i]->ants == 0 || ant->room->neighbors[i]
				== env->end)
				&& ant->room->distance >= (ant->room->neighbors[i]->distance))
		{
			distance = ant->room->neighbors[i]->distance;
			tmp = ant->room->neighbors[i];
		}
		i++;
	}
	return (tmp);
}

bool		ft_moveant(t_lemenv *env, t_ant *ant)
{
	t_lroom		*tmp;

	if (ant->room != env->end)
	{
		tmp = ft_checkneighboors(env, ant);
		if (tmp)
		{
			ft_dispmove(env, tmp, ant);
			ant->room->ants--;
			ant->room = tmp;
			tmp->ants++;
			if (env->regdispmap &&
					(env->follow == 0 || env->follow == ant->ant))
				ft_dispmap(env, ant);
			return (true);
		}
		else if (env->follow == ant->ant || env->followall)
			ft_printf("the ant number {cyan}%3lu{eoc}  {yellow}wait{eoc} in \
room {red}%5s{eoc}\n", ant->ant, ant->room->name);
	}
	return (false);
}

void		ft_domoves(t_lemenv *env)
{
	bool		moved;
	t_ant		*anttmp;

	ft_antspawn(env);
	moved = true;
	while (moved)
	{
		moved = false;
		anttmp = env->antity;
		while (anttmp)
		{
			if (ft_moveant(env, anttmp))
				moved = true;
			anttmp = anttmp->next;
		}
		if (moved && env->follow == 0)
			ft_printf("\n");
		if (moved)
			env->moves++;
	}
}

void		ft_solvelemmap(t_lemenv *env)
{
	t_lroom		*tmp;

	tmp = env->end;
	env->start->distance = INT_MAX;
	env->end->distance = 0;
	ft_setdist(env, tmp, 0);
	if (!env->endreached)
		ft_error(env, "no path", "");
	ft_printf("\n\n");
	ft_domoves(env);
	if (env->total)
		ft_printf("\ntook {green}%d{eoc} steps\n", env->moves);
}

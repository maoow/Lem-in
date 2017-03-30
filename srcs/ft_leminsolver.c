/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leminsolver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:50:05 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/28 15:17:45 by cbinet           ###   ########.fr       */
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
			if(ft_setdist(env, tmp->neighbors[i], dist))
				usefull = true;
		}
		i++;
	}
	if (!usefull)
		tmp->distance = INT_MAX;
	return (usefull);
}

void		ft_antspawn(t_lemenv *env)
{
	t_ant	*tmp;
	size_t	ants;

	env->antity = (t_ant *)malloc(sizeof(t_ant));
	tmp = env->antity;
	tmp->ant = 1;
	tmp->room = env->start;
	ants = 1;
	while (ants < env->ants)
	{
		tmp->next = (t_ant *)malloc(sizeof(t_ant));
		tmp = tmp->next;
		tmp->room = env->start;
		tmp->ant = ants + 1;
		ants++;
	}
	tmp->next = NULL;
}

bool		ft_moveant(t_lemenv *env, t_ant *ant)
{
	size_t		i;
	size_t		distance;
	t_lroom		*tmp;

	if (ant->room != env->end)
	{
		tmp = NULL;
		distance = INT_MAX;
		i = 0;
		while (i < ant->room->neighborsnb)
		{
			if (ant->room->neighbors[i]->distance <= distance &&
			(ant->room->neighbors[i]->ants == 0 || ant->room->neighbors[i] == env->end)
			&& ant->room->distance >= ant->room->neighbors[i]->distance)
			{
				distance = ant->room->neighbors[i]->distance;
				tmp = ant->room->neighbors[i];
			}
			i++;
		}
		if (tmp)
		{
			ft_printf("L%d_%s ", ant->ant, tmp->name); 
			ant->room->ants--;
			ant->room = tmp;
			tmp->ants++;
			return (true);
		}
	}
	return (false);
}

void		ft_solvelemmap(t_lemenv *env)
{
	t_lroom		*tmp;
	t_ant		*anttmp;
	bool		moved;

	tmp = env->end;
	env->start->distance = INT_MAX;
	env->end->distance = 0;
	ft_setdist(env, tmp, 0);
	if (!env->endreached)
		ft_error("","");
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
		if (moved)
		{
			env->moves++;
		ft_printf("\n");
		}

	}
	ft_printf("took %d moves\n", env->moves);
}

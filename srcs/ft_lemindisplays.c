/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemindisplays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 10:35:46 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/11 14:39:22 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*g_colors[7] = {
	"{red}",
	"{green}",
	"{yellow}",
	"{blue}",
	"{pink}",
	"{cyan}",
	"{grey}",
};

void		ft_dispmove(t_lemenv *env, t_lroom *tmp, t_ant *ant)
{
	ant->moves++;
	if (ant->ant == env->follow || env->followall)
	{
		ft_printf("the ant number {cyan}%3lu{eoc} {pink}has left{eoc} room \
		{red}%5s{eoc} for room {green}%5s{eoc} \n", ant->ant, ant->room->name,
		tmp->name);
		if (tmp == env->end)
			ft_printf("\nthe ant number {cyan}%3lu{eoc} {green} reached{eoc} \
			room {cyan}%5s{eoc} in {pink}%ld{eoc} moves\n", ant->ant, tmp->name,
					ant->moves);
	}
	if (env->follow == 0 && !env->followall)
	{
		if (env->colors)
		{
			ft_printf(g_colors[ant->ant % 7]);
			ft_printf("L%d{eoc}-%-5s ", ant->ant, tmp->name);
		}
		else
		{
			ft_printf("L%d-%-5s ", ant->ant, tmp->name);
		}
	}
}

void		ft_dispantposition(t_lemenv *env, t_ant *ant, size_t i)
{
	if (ant)
		if (ant->room == env->rooms[i])
			ft_printf("{red} <= the ant number {green}%d{red} is here !{eoc}",
					ant->ant);
}

void		ft_dispmap(t_lemenv *env, t_ant *ant)
{
	size_t	i;
	size_t	j;

	i = 0;
	ft_printf("\n\nnombre de fourmis : %4d\nnombre de salles :  %4d\n",
			env->ants, env->roomsnb);
	while (i < env->roomsnb)
	{
		ft_printf("\n\n{red}Room           :{eoc}{green}%7s{eoc} \
				(coord :x=%d y=%d)", env->rooms[i]->name, env->rooms[i]->coo.x,
				env->rooms[i]->coo.y);
		if (env->rooms[i]->last)
			ft_printf("  {bggreen}{black}(is the last room){eoc}");
		ft_dispantposition(env, ant, i);
		j = 0;
		ft_printf("\n{cyan}contains       : {eoc} %5d ants\n{green}is neighbor \
				of : {eoc} ", env->rooms[i]->ants);
		while (j < env->rooms[i]->neighborsnb)
		{
			ft_printf(" \"%3s\" ", env->rooms[i]->neighbors[j]->name);
			j++;
		}
		i++;
	}
	ft_printf("\n\n");
}

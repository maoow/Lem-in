/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemgettubes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 08:36:42 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/11 16:37:02 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

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
	if (j >= env->roomsnb)
		ft_error(env, "not a room", true);
	tmproom = env->rooms[j];
	free(tmp);
	tmp = ft_strdup(str + i + 1);
	j = 0;
	while (j < env->roomsnb && ft_strcmp(env->rooms[j]->name, tmp))
		j++;
	if (j >= env->roomsnb)
		ft_error(env, "not a room", true);
	ft_addneighbors(tmproom, env->rooms[j]);
	free(tmp);
	free(str);
}

void		ft_addneighbors(t_lroom *a, t_lroom *b)
{
	size_t		i;
	t_lroom		**tmproom;

	i = 0;
	if (!(tmproom = (t_lroom **)malloc(sizeof(t_lroom *) * (a->neighborsnb + 1))))
		exit(1);
	while (++i <= a->neighborsnb)
		tmproom[i - 1] = a->neighbors[i - 1];
	tmproom[i - 1] = b;
	if (a->neighborsnb != 0)
		free(a->neighbors);
	a->neighbors = tmproom;
	i = 0;
	if (!(tmproom = (t_lroom **)malloc(sizeof(t_lroom *) * (b->neighborsnb + 1))))
		exit(1);
	while (++i <= b->neighborsnb)
		tmproom[i - 1] = b->neighbors[i - 1];
	tmproom[i - 1] = a;
	if (b->neighborsnb != 0)
		free(b->neighbors);
	b->neighbors = tmproom;
	a->neighborsnb++;
	b->neighborsnb++;
}

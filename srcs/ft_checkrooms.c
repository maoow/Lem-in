/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkrooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 12:29:23 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/08 08:59:11 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static bool	ft_checkuniquename(t_lemenv *env, size_t j)
{
	size_t		i;

	i = 0;
	while (i < env->roomsnb)
	{
		if (!ft_strcmp(env->rooms[i]->name, env->rooms[j]->name) && i != j)
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_checkuniquecoo(t_lemenv *env, size_t j)
{
	size_t		i;

	i = 0;
	while (i < env->roomsnb)
	{
		if (env->rooms[i]->coo.y == env->rooms[j]->coo.y && env->rooms[i]->coo.x
				== env->rooms[j]->coo.x && i != j)
			return (false);
		i++;
	}
	return (true);
}

void		ft_checkrooms(t_lemenv *env, size_t room)
{
	if (!ft_checkuniquecoo(env, room))
		ft_error(env, "not unique coo", "", true);
	else if (!ft_checkuniquename(env, room))
		ft_error(env, "not unique name", "", true);
}

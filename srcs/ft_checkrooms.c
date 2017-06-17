/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkrooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 12:29:23 by cbinet            #+#    #+#             */
/*   Updated: 2017/06/17 13:31:34 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Lem-in.h"

bool	ft_checkuniquename(t_lemenv *env, size_t j)
{
	size_t		i;

	i = 0;
	while (env->rooms[i])
	{
		if (!ft_strcmp(env->rooms[i]->name, env->rooms[j]->name) && i != j)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_checkuniquecoo(t_lemenv *env, size_t j)
{
	size_t		i;

	i = 0;
	while (env->rooms[i])
	{
		if (env->rooms[i]->coo.y == env->rooms[j]->coo.y && env->rooms[i]->coo.x == env->rooms[j]->coo.x && i != j)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_checkrooms(t_lemenv *env)
{
	size_t		i;
	bool		error;

	error = false;
	i = 0;
	while (env->rooms[i] && !error)
	{
		if ((error = !ft_checkuniquecoo(env, i)))
			ft_error(env, "not unique coo", "", false);
		if ((error = !ft_checkuniquename(env, i)))
			ft_error(env, "not unique name", "", false);
		i++;
	}
	return (!error);
}

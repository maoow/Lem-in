/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkrooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 12:29:23 by cbinet            #+#    #+#             */
/*   Updated: 2017/06/17 12:52:29 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Lem-in.h"

bool	ft_checkuniquename(t_lemenv *env, size_t j)
{
	size_t		i;

	while (env->rooms[i])
	{
		if (!ft_strcmp(env->rooms[i].name, env->rooms[j].name) && i != j)
			return (false);
		i++
	}
	return (true);
}

bool	ft_checkrooms(t_lemenv *env)
{
	size_t		i;

	i = 0;
	while (env->rooms[i])
	{
		if (!ft_checkuniquename(i))
			ft_error();
		i++
	}
}

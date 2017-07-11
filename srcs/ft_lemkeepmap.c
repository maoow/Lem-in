/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemkeepmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:24:59 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/11 16:54:24 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_lemkeepmap(t_lemenv *env, char *str)
{
	char *tmp;

	if (env->strmap)
	{
		tmp = ft_strjoin(env->strmap, "\n");
		free(env->strmap);
		if (!(env->strmap = ft_strjoin(tmp, str)))
			exit(1);
		free(tmp);
	}
	else
	{
		if (!(env->strmap = ft_strdup(str)))
			exit(1);
	}
}

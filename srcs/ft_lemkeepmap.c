/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemkeepmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:24:59 by cbinet            #+#    #+#             */
/*   Updated: 2017/05/12 15:45:53 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Lem-in.h"

void	ft_lemkeepmap(t_lemenv *env, char *str)
{
	char *tmp;

	if (env->strmap)
	{
		tmp = ft_strjoin(env->strmap, "\n");
		free(env->strmap);
		env->strmap = ft_strjoin(tmp, str);
		free(tmp);
	}
	else
	{
		env->strmap = ft_strdup(str);
	}
}

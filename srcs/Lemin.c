/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:56:29 by cbinet            #+#    #+#             */
/*   Updated: 2017/06/26 16:50:32 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Lem-in.h"

void		ft_error(t_lemenv *env, char *str, char *str2, bool isfatal)
{
//	char	*tmp;

		ft_printf("\n\n%s\n", env->strmap);
	ft_printf("{red}");
	write(2, "\nError\n", 7);
	ft_printf("{eoc}");
	write(2, str, ft_strlen(str));
	write(2, str2, ft_strlen(str2));
	write(2, "\n\n", 1);
	if (isfatal)
		exit(1);
}

static void		initenv(t_lemenv *env)
{
	env->roomsnb = 0;
	env->follow = 0;
	env->ants = 0;
	env->end = NULL;
	env->start = NULL;
	env->rooms = NULL;
	env->endreached = false;
	env->colors = false;
	env->dispmap = false;
	env->regdispmap = false;
	env->followall = false;
	env->total = false;
	env->moves = 0;
	env->strmap = NULL;
}

static void		ft_parse(t_lemenv *env, char *str)
{
	char *tmp;

	if (ft_strchr(str, 't'))
		env->total = true;
	if (ft_strchr(str, 'm'))
		env->dispmap = true;
	if (ft_strchr(str, 'M'))
		env->regdispmap = true;
	if (ft_strchr(str, 'f'))
		env->followall = true;
	if (ft_strchr(str, 'c'))
		env->colors = true;
	if ((tmp = ft_strchr(str, 'a')))
		env->follow = ft_atoi(tmp + 1);
}

void		ft_antspawn(t_lemenv *env)
{
	t_ant	*tmp;
	size_t	ants;

	env->antity = (t_ant *)malloc(sizeof(t_ant));
	tmp = env->antity;
	tmp->ant = 1;
	tmp->moves = 0;
	tmp->room = env->start;
	ants = 1;
	while (ants < env->ants)
	{
		tmp->next = (t_ant *)malloc(sizeof(t_ant));
		tmp = tmp->next;
		tmp->moves = 0;
		tmp->room = env->start;
		tmp->ant = ants + 1;
		ants++;
	}
	tmp->next = NULL;
}

int				main(int ac, char **av)
{
	t_lemenv		env;

	initenv(&env);
	ft_getlemmap(&env);
	if (!env.end)
		ft_error(&env, "No ", "end.", true);
	if (ac == 2)
		ft_parse(&env, av[1]);
	if (env.start)
		env.start->ants = env.ants;
	else
		ft_error(&env, "no start", "", true);
	ft_printf("\n\n%s", env.strmap);
	if (env.dispmap)
		ft_dispmap(&env, NULL);
	if (env.ants && env.start != env.end)
		ft_solvelemmap(&env);
	ft_freeenv(&env);
}


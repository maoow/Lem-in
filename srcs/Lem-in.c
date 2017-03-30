/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:56:29 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/28 13:54:02 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Lem-in.h"

void		ft_error(char *str, char *str2)
{
	char	*tmp;

	while (get_next_line(0, &tmp))
		ft_printf("%s\n", tmp);
	write(2, "\nError\n", 7);
	write(2, str, ft_strlen(str));
	write(2, str2, ft_strlen(str2));
	write(2, "\n", 1);
	exit(1);
}

static void		ft_addneighbors(t_lroom *a, t_lroom *b)
{
	size_t		i;
	t_lroom		**tmproom;

	i = 0;
	tmproom = (t_lroom **)malloc(sizeof(t_lroom *) * (a->neighborsnb + 1));
	while (i < a->neighborsnb)
	{
		tmproom[i] = a->neighbors[i];
		i++;
	}
	tmproom[i] = b;
	if (a->neighborsnb != 0)
		free (a->neighbors);
	a->neighbors = tmproom;
	i = 0;
	tmproom = (t_lroom **)malloc(sizeof(t_lroom *) * (b->neighborsnb + 1));
	while (i < b->neighborsnb)
	{
		tmproom[i] = b->neighbors[i];
		i++;
	}
	tmproom[i] = a;
	if (b->neighborsnb != 0)
		free (b->neighbors);
	b->neighbors = tmproom;
	a->neighborsnb++;
	b->neighborsnb++;

}
static void		ft_addtube(t_lemenv *env, char *str)
{
	char			*tmp;
	t_lroom			*tmproom;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (str[i++] && str[i] != '-');
	tmp = ft_strsub(str, 0, i);
	while (j < env->roomsnb && ft_strcmp(env->rooms[j]->name, tmp))
		j++;
	if (j < env->roomsnb)
		tmproom = env->rooms[j];
	free(tmp);
	tmp = ft_strdup(str + i + 1);
	j = 0;
	while (j < env->roomsnb && ft_strcmp(env->rooms[j]->name, tmp))
		j++;
	if (j < env->roomsnb)
		ft_addneighbors(tmproom, env->rooms[j]);
	free(tmp);
	free(str);

}

static void		ft_pushroom(t_lemenv *env, t_lroom *room)
{
	t_lroom		**tmp;
	size_t		i;

	i = 0;
	env->roomsnb++;
	room->neighborsnb = 0;
	room->ants = 0;
	room->distance = 0;
	tmp = (t_lroom **)malloc(sizeof(t_lroom *) * env->roomsnb);
	while (i < env->roomsnb - 1)
	{
		tmp[i] = env->rooms[i];
		i++;
	}
	tmp[i] = room;
	if (env->rooms)
		free(env->rooms);
	env->rooms = tmp;



}
static t_lroom	*ft_getroom(char *str, t_lemenv *env, bool tube)
{
	t_lroom		*room;
	size_t		i;
	bool		start;
	bool		end;

	i = 0;
	start = false;
	end = false;
	while (str[0] == '#')
	{
		if (!ft_strcmp("##start", str))
			start = true;
		else if (!ft_strcmp("##end", str))
			end = true;
		else
		{
			free(str);
			return (NULL);
		}
		free(str);
		get_next_line(0, &str);
		ft_printf("%s\n",str);
	}
	if (tube || str[0] == 'L' || ft_strchr(str, '-'))
		ft_error("Illegal name: ", str);
	if(!(room = (t_lroom*)malloc(sizeof(t_lroom))))
		exit(1);
	while (str[i++] && str[i] != ' ');
	room->name = ft_strsub(str, 0, i);
	while (str[i++] && !ft_isdigit(str[i]));
	room->coo.x = ft_atoi(str + i);
	while (str[i++] && ft_isdigit(str[i]));
	while (str[i++] && !ft_isdigit(str[i]));
	room->coo.y = ft_atoi(str + i);
	room->ants = 0;
	if (start)
	{
		env->start= room;
		room->ants = env->ants;
	}
	if (end)
		env->end = room;
	room->last = end;
	free(str);
	return (room);
}

static void		ft_getlemmap(t_lemenv *env)
{
	char		*str;
	t_lroom		*room;
	bool		tube;

	tube = false;
	if(get_next_line(0, &str))
	{
		ft_printf("%s\n",str);
		if (ft_isdigit(str[0]))
			env->ants = ft_atoi(str);
		else
			ft_error("No ants", "");
		free(str);
	}
	while(get_next_line(0, &str))
	{
		ft_printf("%s\n",str);
		if (!ft_strchr(str, '-'))
		{
			if ((room = ft_getroom(str, env, tube)))
				ft_pushroom(env, room);
		}
		else
		{
			tube = true;
			ft_addtube(env, str);
		}
	}

}

static void		ft_dispmap(t_lemenv *env)
{
	size_t  i;
	size_t	j;

	i = 0;
	ft_printf("nombre de fourmis : %4d\nnombre de salles :  %4d\n", env->ants, env->roomsnb);
	ft_printf("\n\n");
	while (i < env->roomsnb)
	{
		ft_printf("{red}Salle :{eoc}     %s x: %d y: %d",env->rooms[i]->name, env->rooms[i]->coo.x, env->rooms[i]->coo.y);
		if (env->rooms[i]->last)
			ft_printf("  {bggreen}(est la salle d'arrivee){eoc}");
		j = 0;
		ft_printf("\n{cyan}contient :{eoc} %d fourmis\n", env->rooms[i]->ants);
		ft_printf("{green}touche   :{eoc} ");
		while (j < env->rooms[i]->neighborsnb)
		{
			ft_printf("%s  ", env->rooms[i]->neighbors[j]->name);
			j++;
		}
		ft_printf("\n\n");
		i++;
	}
}
int				main()
{
	t_lemenv		env;

	env.roomsnb = 0;
	env.end = NULL;
	env.start = NULL;
	env.rooms = NULL;
	ft_getlemmap(&env);
	env.endreached = false;
	env.moves = 0;
	if (!env.end)
		ft_error("No ", "end.");
	env.start->ants = env.ants;
	ft_dispmap(&env);
	if (env.ants && env.start != env.end)
		ft_solvelemmap(&env);
}

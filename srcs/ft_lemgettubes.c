











#include "../includes/Lem-in.h"

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
	if (j < env->roomsnb)
	{
		tmproom = env->rooms[j];
		free(tmp);
		tmp = ft_strdup(str + i + 1);
		j = 0;
		while (j < env->roomsnb && ft_strcmp(env->rooms[j]->name, tmp))
			j++;
		if (j < env->roomsnb)
		{
			ft_addneighbors(tmproom, env->rooms[j]);
			free(tmp);
			free(str);
		}
		else
			ft_error(env, tmp, " is not a room", true);
	}
	else
		ft_error(env, tmp, " is not a room", true);
}

void		ft_addneighbors(t_lroom *a, t_lroom *b)
{
	size_t		i;
	t_lroom		**tmproom;

	i = 0;
	tmproom = (t_lroom **)malloc(sizeof(t_lroom *) * (a->neighborsnb + 1));
	while (++i <= a->neighborsnb)
		tmproom[i - 1] = a->neighbors[i - 1];
	tmproom[i - 1] = b;
	if (a->neighborsnb != 0)
		free(a->neighbors);
	a->neighbors = tmproom;
	i = 0;
	tmproom = (t_lroom **)malloc(sizeof(t_lroom *) * (b->neighborsnb + 1));
	while (++i <= b->neighborsnb)
		tmproom[i - 1] = b->neighbors[i - 1];
	tmproom[i - 1] = a;
	if (b->neighborsnb != 0)
		free(b->neighbors);
	b->neighbors = tmproom;
	a->neighborsnb++;
	b->neighborsnb++;
}


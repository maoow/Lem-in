/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:19:37 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/15 16:26:41 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFF_SIZE
# define BUFF_SIZE 2048
#endif
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);

#endif

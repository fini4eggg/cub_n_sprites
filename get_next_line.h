/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 05:13:19 by bryella           #+#    #+#             */
/*   Updated: 2021/01/07 22:09:39 by bryella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
int			get_next_line(int fd, char **line);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);

#endif

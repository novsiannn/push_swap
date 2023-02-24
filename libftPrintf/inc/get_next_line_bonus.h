/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:34:20 by novsiann          #+#    #+#             */
/*   Updated: 2023/02/22 16:03:34 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
//Libraries that I use
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
//My functions
char	*get_next_line(int fd);
char	*ft_strchr_getnextline(char *s, int c);
char	*ft_read_and_save(int fd, char *save);
char	*ft_get_line(char *save);
char	*ft_save(char *old_str);
char	*ft_strjoin_check(char *s1, char *s2);
char	*ft_strjoin_getnextline(char *s1, char *s2);
size_t	ft_strlen_getnextline(char *str);

#endif

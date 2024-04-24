/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_reader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparis <fparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:50:06 by fparis            #+#    #+#             */
/*   Updated: 2024/04/24 17:55:16 by fparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_READER_H

# define LINE_READER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"

char	*get_next_line(int fd);
int		ft_atoi(const char *nptr);

#endif

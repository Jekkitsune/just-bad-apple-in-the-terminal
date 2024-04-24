/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparis <fparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:29:25 by fparis            #+#    #+#             */
/*   Updated: 2024/04/24 17:57:43 by fparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_reader.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	unsigned int	un_n;
	int				n;

	i = 0;
	un_n = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		un_n = un_n * 10 + (nptr[i] - '0');
		i++;
	}
	n = un_n * sign;
	return (n);
}

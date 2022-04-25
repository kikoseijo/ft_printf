/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:37:17 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/04/25 17:51:22 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	init_tlist(t_list flags)
{
	flags.width = 0;
	flags.precision = 0;
	flags.points = 0;
	return (flags);
}

int	is_special_char(char c)
{
	int		i;
	char	special_chars[10];

	special_chars[0] = 'c';
	special_chars[1] = 's';
	special_chars[2] = 'p';
	special_chars[3] = 'd';
	special_chars[4] = 'i';
	special_chars[5] = 'u';
	special_chars[6] = 'x';
	special_chars[7] = 'X';
	special_chars[8] = '%';
	special_chars[9] = '\0';
	i = 0;
	while (special_chars[i])
	{
		if (c == special_chars[i])
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:17:35 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/04/25 17:48:36 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** TO DELETE
*/
# include <stdio.h>
/*
** libraries
*/
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_list
{
	int			width;
	int			points;
	int			precision;
}				t_list;

typedef struct s_print
{
	int			curr_index;
	int			is_error;
	const char	*src_str;
	char		*print_str;
	char		*error_msg;
}				t_print;

int				ft_printf(const char *format, ...);
void			ft_parse_item(t_print *model, void *param);

#endif

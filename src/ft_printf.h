/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:17:35 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/03 16:41:38 by jseijo-p         ###   ########.fr       */
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
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_print
{
	int		str_len;
	int		is_error;
	char	*str;
	int		width;
	int		points;
	int		precision;
	va_list	args;
}			t_print;

int			ft_printf(const char *format, ...);
void		ft_free_model(t_print *model);
int			is_special_char(char c);
void		ft_print_p(t_print *model, unsigned long long nb);
void		ft_puthex(t_print *model, unsigned long long nb);
void		ft_print_int(t_print *model, int nb);
#endif

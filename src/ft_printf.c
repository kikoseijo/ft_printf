/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:16:32 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/03 12:01:48 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_s(t_print *m, char *str)
{
	ft_putstr_fd((char *)str, 1);
	m->str++;
	m->str_len += ft_strlen(str);
}

static void	ft_print_c(t_print *m, int c)
{
	ft_putchar_fd((char)c, 1);
	m->str++;
	m->str_len++;
}

static void	ft_parse_item(t_print *m)
{
	m->str++;
	if (*m->str == 'c')
		ft_print_c(m, va_arg(m->args, int));
	else if (*m->str == '%')
		ft_print_c(m, '%');
	else if (*m->str == 's')
		ft_print_s(m, va_arg(m->args, char *));
}

void	ft_free_model(t_print *model)
{
	if (model->str)
		free((void *)model->str);
	if (model)
		free(model);
}

int	ft_printf(const char *format, ...)
{
	t_print	*model;

	model = (t_print *)malloc(sizeof(t_print));
	if (!model)
		return (0);
	va_start(model->args, format);
	model->str = (char *)format;
	model->str_len = 0;
	while (*model->str)
	{
		if (*model->str == '%' && is_special_char(*(model->str + 1)))
			ft_parse_item(model);
		else
			ft_print_c(model, *(model->str + 1));
	}
	va_end(model->args);
	return (model->str_len);
}
/*
** // ft_free_model(model);
*/

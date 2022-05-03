/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:16:32 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/03 10:03:13 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_item(t_print *m)
{
	m->str++;
	m->str_len += 1;
	printf("%d %c:%s\n", m->str_len, *m->str, va_arg(m->args, void *));
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
		va_start(model->args, format);
	model->str = (char *)format;
	model->str_len = 0;
	while (*model->str)
	{
		if (*model->str == '%' && is_special_char(*model->str + 1))
			ft_parse_item(model);
		else
		{
			ft_putchar_fd(*model->str, 1);
			model->str++;
			model->str_len += 1;
		}
	}
	va_end(model->args);
	return (model->str_len);
}
/*
** // ft_free_model(model);
*/

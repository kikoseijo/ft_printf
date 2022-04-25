/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:16:32 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/04/25 17:57:49 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_item(t_print *model, void *param)
{
	printf("%d %s\n", model->curr_index, param);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	t_print	*model;

	model = (t_print *)malloc(sizeof(t_print));
	if (!model)
		return (0);
	va_start(args, format);
	model->src_str = format;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && is_special_char(format[i + 1]))
		{
			model->curr_index = i;
			ft_parse_item(model, va_arg(args, void *));
			i++;
		}
		i++;
	}
	va_end(args);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:37:17 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/05 18:33:19 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_integer(t_print *model, int nb)
{
	long long	n;

	n = (long long)nb;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		model->str_len += 1;
		n *= -1;
	}
	if (n > 9)
		ft_print_integer(model, n / 10);
	n = n % 10;
	model->str_len += 1;
	ft_putchar_fd(n + '0', 1);
}

void	ft_print_int(t_print *model, int nb)
{
	ft_print_integer(model, nb);
	model->str++;
}

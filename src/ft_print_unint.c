/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:58:22 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/05 18:03:08 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_uint(t_print *model, unsigned int nb)
{
	unsigned int	n;

	n = nb;
	if (n < 0)
		n *= -1;
	if (n > 9)
		ft_print_uint(model, n / 10);
	n = n % 10;
	model->str_len += 1;
	ft_putchar_fd(n + '0', 1);
}

void	ft_print_uint_main(t_print *model, unsigned int nb)
{
	ft_print_uint(model, nb);
	model->str++;
}

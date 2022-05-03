/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:37:17 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/03 17:36:10 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_uint(t_print *model, unsigned int nb)
{
	unsigned int	n;

	n = nb;
	if (n < 0)
	{
		n *= -1;
	}
	if (n > 9)
	{
		ft_print_uint(model, n / 10);
	}
	n = n % 10;
	model->str_len += 1;
	ft_putchar_fd(n + '0', 1);
}

void	ft_print_int(t_print *model, int nb)
{
	long long	n;

	n = (long long)nb;
	if (n < 0 && (int)*model->str == 'u')
	{
		n *= -1;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', 1);
		model->str_len += 1;
		n *= -1;
	}
	if (n > 9)
	{
		ft_print_int(model, n / 10);
	}
	n = n % 10;
	model->str_len += 1;
	ft_putchar_fd(n + '0', 1);
}

void	ft_puthex(t_print *model, unsigned long long nb)
{
	if (nb >= 16)
		ft_puthex(model, (unsigned long long)nb / 16);
	model->str_len += 1;
	ft_putchar_fd("0123456789abcdef"[nb % 16], 1);
}

void	ft_print_p(t_print *model, unsigned long long nb)
{
	ft_putstr_fd("0x", 1);
	model->str_len += 2;
	model->str++;
	ft_puthex(model, nb);
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

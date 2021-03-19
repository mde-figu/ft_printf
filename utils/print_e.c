/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:55:12 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/18 22:55:23 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static double	absolute_value(double n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static void		print_notation(int exp, char *str, size_t *printed_len)
{
	char *temp;

	if (exp < 0)
	{
		ft_putstr("e-");
		exp *= -1;
	}
	else
		ft_putstr("e+");
	if (exp < 10)
		ft_putchar('0');
	temp = ft_itoa(exp);
	ft_putstr(temp);
	*printed_len += 4;
	free(temp);
	free(str);
}

void			print_e(va_list args, t_params *var_params, size_t *printed_len)
{
	double	n;
	double	abs_value;
	int		exp;
	char	*str;

	n = va_arg(args, double);
	abs_value = absolute_value(n);
	exp = 0;
	while (abs_value < 1)
	{
		n *= 10;
		abs_value *= 10;
		exp -= 1;
	}
	while (abs_value >= 10)
	{
		n /= 10;
		abs_value /= 10;
		exp += 1;
	}
	if (var_params->has_precision++ == 0)
		var_params->precision_value = 6;
	str = ft_ftoa(n, var_params->precision_value);
	*printed_len += print_in_screen(str, var_params);
	print_notation(exp, str, printed_len);
}

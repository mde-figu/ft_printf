/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:57:34 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/18 22:57:47 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_x_upper(va_list args, t_params *var_params, size_t *printed_len)
{
	int		n;
	char	*str;

	n = va_arg(args, int);
	str = ft_int_to_hex(n);
	n = -1;
	while (str[++n])
		str[n] = ft_toupper(str[n]);
	if (*str == '0' && var_params->precision_value == 0\
		&& var_params->has_precision)
		*str = '\0';
	*printed_len += print_in_screen(str, var_params);
	free(str);
}

void	print_x(va_list args, t_params *var_params, size_t *printed_len)
{
	int		n;
	char	*str;

	n = va_arg(args, int);
	str = ft_int_to_hex(n);
	if (*str == '0' && var_params->precision_value == 0\
		&& var_params->has_precision)
		*str = '\0';
	*printed_len += print_in_screen(str, var_params);
	free(str);
}

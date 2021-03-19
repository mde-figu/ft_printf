/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:55:32 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/18 22:55:42 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_f(va_list args, t_params *var_params, size_t *printed_len)
{
	double	n;
	char	*str;

	n = va_arg(args, double);
	if (var_params->has_precision++ == 0)
		var_params->precision_value = 6;
	str = ft_ftoa(n, var_params->precision_value);
	*printed_len += print_in_screen(str, var_params);
	free(str);
}

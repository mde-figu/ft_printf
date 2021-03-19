/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:54:53 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/18 22:55:03 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_u(va_list args, t_params *var_params, size_t *printed_len)
{
	char	*str;

	str = ft_utoa(va_arg(args, unsigned int));
	if (*str == '0' && !var_params->precision_value &&\
		var_params->has_precision)
		*str = '\0';
	*printed_len += print_in_screen(str, var_params);
	free(str);
}

void	print_d(va_list args, t_params *var_params, size_t *printed_len)
{
	char	*str;

	str = ft_itoa(va_arg(args, int));
	if (*str == '0' && !var_params->precision_value &&\
		var_params->has_precision)
		*str = '\0';
	*printed_len += print_in_screen(str, var_params);
	free(str);
}

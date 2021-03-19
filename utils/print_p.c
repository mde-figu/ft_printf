/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:56:08 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/18 22:56:24 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_p(va_list args, t_params *var_params, size_t *printed_len)
{
	long long	n;
	char		*str;
	char		*temp_str;
	int			len;

	n = va_arg(args, long long);
	str = ft_int_to_hex(n);
	if (var_params->has_precision && var_params->precision_value == 0 && n == 0)
		*str = 0;
	len = ft_strlen(str);
	if (var_params->precision_value > len && !var_params->has_minus)
	{
		temp_str = ft_calloc(var_params->precision_value - len, sizeof(char));
		ft_memset(temp_str, '0', var_params->precision_value - len);
		str = ft_strjoin(temp_str, str);
	}
	temp_str = ft_strjoin("0x", str);
	*printed_len += print_in_screen(temp_str, var_params);
	free(str);
	free(temp_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:54:07 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/18 22:54:16 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_c(va_list args, t_params *var_params, size_t *printed_len)
{
	char	str;
	char	*new_str;

	str = va_arg(args, int);
	new_str = ft_calloc(2, sizeof(char));
	new_str[0] = str;
	if (new_str[0] == 0)
	{
		var_params->width_value--;
		*printed_len += print_in_screen(new_str, var_params) + 1;
		free(new_str);
	}
	else
	{
		*printed_len += print_in_screen(new_str, var_params);
		free(new_str);
	}
}

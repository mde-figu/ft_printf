/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:56:47 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/18 22:56:53 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_pcnt(t_params *var_params, size_t *printed_len)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	*str = '%';
	*printed_len += print_in_screen(str, var_params);
	free(str);
}

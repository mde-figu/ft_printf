/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:55:53 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/18 22:56:04 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_n(va_list args, size_t *printed_len)
{
	int	*i;

	i = va_arg(args, int *);
	*i = *printed_len;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:49:44 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/18 22:49:56 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fit_norm(char *temp, size_t *printed_len, va_list args)
{
	size_t	*skip_len;

	skip_len = ft_calloc(2, sizeof(size_t));
	*skip_len = 0;
	while (temp[*skip_len])
	{
		if (temp[*skip_len] == '%')
		{
			print_variable(temp + *skip_len + 1, skip_len, args, printed_len);
		}
		else
		{
			ft_putchar(temp[*skip_len]);
			*skip_len += 1;
			*printed_len += 1;
		}
	}
	free(skip_len);
}

size_t		ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	*printed_len;
	char	*temp;
	size_t	size;

	va_start(args, str);
	printed_len = ft_calloc(2, sizeof(size_t));
	*printed_len = 0;
	temp = ft_strdup(str);
	fit_norm(temp, printed_len, args);
	va_end(args);
	free(temp);
	size = *printed_len;
	free(printed_len);
	return (size);
}

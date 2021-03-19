/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:19:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/18 23:19:28 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*precision_nb(char *str, int precis, int len, int signal)
{
	char *new_str;

	new_str = ft_calloc(precis + signal + 1, sizeof(char));
	if (signal)
		new_str[0] = '-';
	while (precis + signal - len)
	{
		new_str[precis + (signal * 2) - len - 1] = '0';
		precis--;
	}
	ft_strlcpy(new_str + ft_strlen(new_str) - signal, str + signal, len + 1);
	return (new_str);
}

static int	print_in_screen_b(t_params *var_params, size_t printed_char_len,
				int signal, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (var_params->has_precision && (var_params->precision_value == 0\
		|| var_params->precision_value == 1))
		if (str[0] == 0)
			print_multiple_char(var_params->width_value, ' ');
		else
			print_multiple_char(printed_char_len - len, ' ');
	else
	{
		if (var_params->precision_value > 0)
			print_multiple_char(printed_char_len - len, ' ');
		else
		{
			if (signal && var_params->width_value > len)
				ft_putstr("-");
			print_multiple_char(printed_char_len - len, '0');
			if (signal && var_params->width_value > len)
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

static int	print_in_screen_a(t_params *var_params, size_t printed_char_len,
				int signal, char *str)
{
	int		len;
	int		add;
	char	type;

	len = ft_strlen(str);
	type = var_params->type;
	add = 0;
	if (var_params->has_minus)
	{
		if (type == 'c' && str[0] == 0)
			ft_putchar(0);
		ft_putstr(str);
		print_multiple_char(printed_char_len - len, ' ');
	}
	else if (var_params->has_zero)
		add += print_in_screen_b(var_params, printed_char_len, signal, str);
	else if ((size_t)var_params->width_value == printed_char_len)
		print_multiple_char(printed_char_len - len, ' ');
	return (add);
}

static void	print_full(char *str, t_params *var_params, char type)
{
	if (!var_params->has_minus)
	{
		if (type == 'c' && str[0] == 0)
			ft_putchar(0);
		ft_putstr(str);
	}
}

size_t		print_in_screen(char *str, t_params *var_params)
{
	size_t	printed_char_len;
	int		len;
	int		signal;
	char	type;
	char	*temp_str;

	signal = 0;
	temp_str = 0;
	type = var_params->type;
	if ((type == 'd' || type == 'i') && str[0] == '-')
		signal = 1;
	len = ft_strlen(str) - signal;
	if ((type == 'd' || type == 'i' || type == 'u' || type == 'x'\
		|| type == 'X') && var_params->precision_value > len)
	{
		temp_str = precision_nb(str, var_params->precision_value, len, signal);
		str = temp_str;
	}
	len = ft_strlen(str);
	printed_char_len = maximum(2, var_params->width_value, (int)len);
	str += print_in_screen_a(var_params, printed_char_len, signal, str);
	print_full(str, var_params, type);
	if (!(temp_str == 0))
		free(temp_str);
	return (printed_char_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters_for_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:57:55 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/18 23:33:16 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t		parameters_length(const char *str, size_t *skip_len)
{
	size_t	i;

	i = 0;
	while (!ft_isalpha(str[i]) && str[i] != '%')
		i++;
	*skip_len += i + 2;
	return (i);
}

void		get_params(const char *str, size_t skip_len, va_list args,
				t_params *var_params)
{
	size_t	i;

	i = set_flags(str, var_params);
	i += set_width(str + i, var_params, args);
	set_precision((char *)str + i, var_params, args);
	var_params->type = str[skip_len];
}

static void	ifs(t_params *var_params, va_list args, size_t *printed_len)
{
	if (var_params->type == 'c')
		print_c(args, var_params, printed_len);
	else if (var_params->type == 'd' || var_params->type == 'i')
		print_d(args, var_params, printed_len);
	else if (var_params->type == 'p')
		print_p(args, var_params, printed_len);
	else if (var_params->type == '%')
		print_pcnt(var_params, printed_len);
	else if (var_params->type == 's')
		print_s(args, var_params, printed_len);
	else if (var_params->type == 'u')
		print_u(args, var_params, printed_len);
	else if (var_params->type == 'x')
		print_x(args, var_params, printed_len);
	else if (var_params->type == 'X')
		print_x_upper(args, var_params, printed_len);
	else if (var_params->type == 'n')
		print_n(args, printed_len);
	else if (var_params->type == 'f')
		print_f(args, var_params, printed_len);
	else if (var_params->type == 'e')
		print_e(args, var_params, printed_len);
}

void		print_variable(const char *str, size_t *skip_len, va_list args,
				size_t *printed_len)
{
	t_params	*var_params;

	var_params = ft_calloc(2, sizeof(t_params));
	get_params(str, parameters_length(str, skip_len), args, var_params);
	ifs(var_params, args, printed_len);
	free((t_params *)var_params);
}

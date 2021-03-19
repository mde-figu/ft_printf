/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:48:52 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/18 22:49:19 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

size_t			ft_printf(const char *str, ...);
size_t			parameters_length(const char *str, size_t *skip_len);

typedef struct	s_params
{
	char		type;
	char		has_zero;
	char		has_minus;
	int			has_width;
	int			has_precision;
	int			width_value;
	int			precision_value;
}				t_params;

void			print_variable(const char *str, size_t *skip_len, va_list args,
					size_t *printed_len);
void			get_params(const char *str, size_t skip_len, va_list args,
					t_params *var_params);
int				set_flags(const char *str, t_params *var_params);
size_t			set_width(const char *str, t_params *var_params, va_list args);
void			set_precision(char *str, t_params *var_params, va_list args);
void			print_c(va_list args, t_params *var_params,
					size_t *printed_len);
void			print_d(va_list args, t_params *var_params,
					size_t *printed_len);
void			print_p(va_list args, t_params *var_params,
					size_t *printed_len);
void			print_pcnt(t_params *var_params, size_t *printed_len);
void			print_s(va_list args, t_params *var_params,
					size_t *printed_len);
void			print_u(va_list args, t_params *var_params,
					size_t *printed_len);
void			print_x(va_list args, t_params *var_params,
					size_t *printed_len);
void			print_x_upper(va_list args, t_params *var_params,
					size_t *printed_len);
void			print_n(va_list args, size_t *printed_len);
void			print_f(va_list args, t_params *var_params,
					size_t *printed_len);
void			print_e(va_list args, t_params *var_params,
					size_t *printed_len);
size_t			print_in_screen(char *str, t_params *var_params);
char			*ft_utoa(unsigned int n);
void			print_atributes(t_params *var_params);

#endif

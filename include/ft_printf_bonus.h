/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:45:30 by madelmen          #+#    #+#             */
/*   Updated: 2024/10/27 01:51:43 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	char	*join;
	int		minus;
	int		zero;
	int		dot;
	int		star;
	int		width;
	int		precision;
	int		plus;
	int		space;
	int		hash;
}	t_flags;

int		ft_print_char(va_list args, t_flags *flags);
int		ft_print_string(va_list args, t_flags *flags);
int		ft_print_int(va_list args, t_flags *flags);
int		ft_print_uint(va_list args, t_flags *flags);
int		ft_print_hex(va_list args, t_flags *flags, char specifier);
int		ft_print_pointer(va_list args, t_flags *flags);
int		ft_printf(const char *format, ...);
int		ft_dispatch_format(char format, va_list args, t_flags *flags);
int		ft_parsing(const char **format, va_list args, t_flags *flags);
int		ft_print_padding(int padding);
int		ft_print_with_precision(char *str, int precision);
int		ft_proces(t_flags *flags, int printed_len, int total_width);
void	ft_cleanup_flags(t_flags *flags);
int		ft_apply_zero_padding(int printed_len, t_flags *flags);
void	ft_parse_number(const char **format, t_flags *flags);
void	ft_set_flag(const char **format, t_flags *flags);


#endif

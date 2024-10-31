/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch_format_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:54:06 by madelmen          #+#    #+#             */
/*   Updated: 2024/10/26 18:15:22 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	ft_dispatch_format(char format, va_list args, t_flags *flags)
{
	if (format == 'c')
		return (ft_print_char(args, flags));
	else if (format == 's')
		return (ft_print_string(args, flags));
	else if (format == 'd' || format == 'i')
		return (ft_print_int(args, flags));
	else if (format == 'u')
		return (ft_print_uint(args, flags));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(args, flags, format));
	else if (format == 'p')
		return (ft_print_pointer(args, flags));
	else if (format == '%')
		return (write (1, "%%", 1));
	return (write(1, &format, 1));
}

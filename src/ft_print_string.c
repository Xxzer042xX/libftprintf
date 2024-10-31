/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:32:02 by madelmen          #+#    #+#             */
/*   Updated: 2024/10/27 01:28:07 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../libft/libft.h"

int	ft_print_string(va_list args, t_flags *flags)
{
	char	*str;
	int		str_len;
	int		printed_len;
	int		total_width;

	if (flags->join)
		str = flags->join;
	else
		str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (flags->dot && flags->precision >= 0 && flags->precision < str_len)
		printed_len = flags->precision;
	else
		printed_len = str_len;
	if (flags->width > printed_len)
		total_width = flags->width;
	else
		total_width = printed_len;
	if (flags->join && flags->join != str)
		free(flags->join);
	flags->join = str;
	return (ft_proces(flags, printed_len, total_width));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:41:04 by madelmen          #+#    #+#             */
/*   Updated: 2024/10/28 20:41:08 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	ft_print_char(va_list args, t_flags *flags)
{
	char	c;
	int		printed_len;
	int		total_width;

	c = (char)va_arg(args, int);
	printed_len = 1;
	if (flags->width > printed_len)
		total_width = flags->width;
	else
		total_width = printed_len;
	flags->join = &c;
	return (ft_proces(flags, printed_len, total_width));
}

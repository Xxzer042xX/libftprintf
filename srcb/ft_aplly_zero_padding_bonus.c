/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aplly_zero_padding_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:26:52 by madelmen          #+#    #+#             */
/*   Updated: 2024/10/31 14:18:18 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	ft_apply_zero_padding(int printed_len, t_flags *flags)
{
	int	padding_char;
	int	char_count;

	char_count = 0;
	if (flags->zero && !flags->dot)
		padding_char = '0';
	else if (flags->dot)
		padding_char = '0';
	else
		padding_char = ' ';
	while ((flags->width > printed_len) || (flags->precision > printed_len))
	{
		if (write(1, &padding_char, 1) == -1)
			return (-1);
		if (flags->precision)
			flags->precision--;
		else
			flags->width--;
		char_count++;
	}
	return (char_count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proces_width_and_precision.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:51:05 by madelmen          #+#    #+#             */
/*   Updated: 2024/10/28 20:34:06 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	ft_proces(t_flags *flags, int printed_len, int total_width)
{
	int	char_count;
	int	result;

	char_count = 0;
	if (flags->minus)
	{
		result = ft_print_with_precision(flags->join, printed_len);
		if (result == -1)
			return (-1);
		char_count += result;
		result = ft_print_padding(total_width - printed_len);
		if (result == -1)
			return (-1);
		char_count += result;
		return (char_count);
	}
	result = ft_print_padding(total_width - printed_len);
	if (result == -1)
		return (-1);
	char_count += result;
	result = ft_print_with_precision(flags->join, printed_len);
	if (result == -1)
		return (-1);
	char_count += result;
	return (char_count);
}

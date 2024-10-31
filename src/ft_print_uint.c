/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:32:20 by madelmen          #+#    #+#             */
/*   Updated: 2024/10/23 05:58:40 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../libft/libft.h"

int	ft_print_uint(va_list args, t_flags *flags)
{
	int				len;
	unsigned int	n;
	char			*str;
	int				count;

	count = 0;
	n = va_arg(args, unsigned int);
	str = ft_ulltoa((unsigned long long)n);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (!flags->minus)
		count += ft_apply_zero_padding(len + count, flags);
	count += write(1, str, len);
	if (flags->minus)
		count += ft_apply_zero_padding(len, flags);
	free(str);
	return (count);
}

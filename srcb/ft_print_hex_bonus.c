/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:05:02 by madelmen          #+#    #+#             */
/*   Updated: 2024/10/31 19:18:26 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../libft/libft.h"

static int	ft_prefix(t_flags *flags, char spec, unsigned int n, int *count)
{
	if (flags->hash && n != 0 && spec == 'x')
	{
		*count += 2;
		return (write(1, "0x", 2));
	}
	else if (flags->hash && n != 0 && spec == 'X')
	{
		*count += 2;
		return (write(1, "0X", 2));
	}
	return (0);
}

static int	ft_call_padding(t_flags *flags, int len, int *count, char *str)
{
	int	check;

	check = 0;
	if (!flags->minus)
	{
		check = ft_apply_zero_padding(len + *count, flags);
		if (check == -1)
			return (-1);
		*count += check;
	}
	if (write(1, str, len) == -1)
		return (-1);
	*count += len;
	if (flags->minus)
	{
		check = ft_apply_zero_padding(len, flags);
		if (check == -1)
			return (-1);
		*count += check;
	}
	return (0);
}

int	ft_print_hex(va_list args, t_flags *flags, char specifier)
{
	unsigned int	n;
	char			*str;
	int				len;
	int				count;

	count = 0;
	len = 0;
	n = va_arg(args, unsigned int);
	if (specifier == 'x')
		str = ft_itoa_base(n, 16, 0);
	else
		str = ft_itoa_base(n, 16, 1);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (ft_prefix(flags, specifier, n, &count) == -1)
		return (free(str), -1);
	if (ft_call_padding(flags, len, &count, str) == -1)
		return (free(str), -1);
	return (free(str), count);
}

/*
int	ft_print_hex(va_list args, t_flags *flags, char specifier)
{
	unsigned int	n;
	char			*str;
	int				len;
	int				count;

	count = 0;
	n = va_arg(args, unsigned int);
	if (specifier == 'x')
		str = ft_itoa_base(n, 16, 0);
	else
		str = ft_itoa_base(n, 16, 1);
	if (!str)
		return (-1);
	if (flags->hash && n != 0 && specifier == 'x')
		count += write(1, "0x", 2);
	else if (flags->hash && n != 0 && specifier == 'X')
		count += write(1, "0X", 2);
	len = ft_strlen(str);
	if (!flags->minus)
		count += ft_apply_zero_padding(len + count, flags);
	count += write(1, str, len);
	if (flags->minus)
		count += ft_apply_zero_padding(len, flags);
	free(str);
	return (count);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:32:13 by madelmen          #+#    #+#             */
/*   Updated: 2024/10/31 22:11:33 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../libft/libft.h"

static int	print_sign(int n, t_flags *flags, int *count)
{
	if (n >= 0 && flags->plus)
	{
		if (write(1, "+", 1) == -1)
			return (-1);
		*count += 1;
	}
	else if (n >= 0 && flags->space)
	{
		if (write(1, " ", 1) == -1)
			return (-1);
		*count += 1;
	}
	return (0);
}

static int	apply_padding_before(int len, t_flags *flags, int *count)
{
	int	check;

	check = 0;
	if (!flags->minus && !flags->dot)
		check = ft_apply_zero_padding(len + *count, flags);
	else if (flags->dot)
		check = ft_apply_zero_padding(len, flags);
	if (check == -1)
		return (-1);
	*count += check;
	return (0);
}

static int	apply_padding_after(int len, t_flags *flags, int *count)
{
	int	check;

	if (flags->minus)
	{
		check = ft_apply_zero_padding(len, flags);
		if (check == -1)
			return (-1);
		*count += check;
	}
	return (0);
}

static int	ft_process_padding(t_flags *flags, char *str, int len, int *count)
{
	if (apply_padding_before(len, flags, count) == -1)
		return (-1);
	if (write(1, str, len) == -1)
		return (-1);
	*count += len;
	if (apply_padding_after(len, flags, count) == -1)
		return (-1);
	return (0);
}

int	ft_print_int(va_list args, t_flags *flags)
{
	int		n;
	char	*str;
	int		len;
	int		count;

	count = 0;
	n = va_arg(args, int);
	if (n < 0 && (flags->zero || flags->dot) && n != -2147483648)
	{
		n *= -1;
		if (write(1, "-", 1) == -1)
			return (-1);
		count += 1;
	}
	str = ft_itoa(n);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (print_sign(n, flags, &count) == -1)
		return (free(str), -1);
	if (ft_process_padding(flags, str, len, &count) == -1)
		return (free(str), -1);
	return (free(str), count);
}

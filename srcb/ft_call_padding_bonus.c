/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_padding_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelmeni <eljok87@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:11:11 by mdelmeni          #+#    #+#             */
/*   Updated: 2024/11/01 16:11:11 by mdelmeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	ft_call_padding(t_flags *flags, int len, int *count, char *str)
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

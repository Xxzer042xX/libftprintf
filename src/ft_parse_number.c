/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:42:05 by madelmen          #+#    #+#             */
/*   Updated: 2024/10/28 20:42:08 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../libft/libft.h"

// Fonction pour lire les nombres dans le format
void	ft_parse_number(const char **format, t_flags *flags)
{
	int	number;

	number = 0;
	while (ft_isdigit(**format))
	{
		number = number * 10 + (**format - '0');
		(*format)++;
	}
	if (flags->dot)
		flags->precision = number;
	else
		flags->width = number;
	if (flags->minus)
		flags->zero = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:33:08 by madelmen          #+#    #+#             */
/*   Updated: 2024/10/28 20:33:19 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

// Fonction pour assigner les flags
void	ft_set_flag(const char **format, t_flags *flags)
{
	if (**format == '-')
		flags->minus = 1;
	else if (**format == '0')
		flags->zero = 1;
	else if (**format == '#')
		flags->hash = 1;
	else if (**format == '+')
		flags->plus = 1;
	else if (**format == ' ')
		flags->space = 1;
	else if (**format == '.')
		flags->dot = 1;
	(*format)++;
}

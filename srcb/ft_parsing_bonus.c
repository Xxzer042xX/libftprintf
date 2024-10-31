/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 07:25:50 by madelmen          #+#    #+#             */
/*   Updated: 2024/10/27 02:29:50 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../libft/libft.h"

// Fonction de parsing des flags et spécificateurs
int	ft_parsing(const char **format, va_list args, t_flags *flags)
{
	ft_memset(flags, 0, sizeof(t_flags));
	while (**format && !ft_strchr("cspdiuxX%", **format))
	{
		if (ft_isflags((int)**format))
			ft_set_flag(format, flags);
		else if (ft_isdigit(**format))
			ft_parse_number(format, flags);
		else
			format++;
	}
	if (**format)
		return (ft_dispatch_format(**format, args, flags));
	return (-1);
}

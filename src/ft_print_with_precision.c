/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_with_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:35:20 by madelmen          #+#    #+#             */
/*   Updated: 2024/10/28 20:36:37 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

// Fonction pour gérer la précision et limiter l'affichage de la chaîne
int	ft_print_with_precision(char *str, int precision)
{
	int	i;
	int	char_count;

	i = 0;
	char_count = 0;
	while (i < precision)
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		char_count++;
		i++;
	}
	return (char_count);
}

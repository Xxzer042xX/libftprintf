/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelmen <madelmen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:45:31 by madelmen          #+#    #+#             */
/*   Updated: 2024/10/28 20:37:31 by madelmen         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

// Fonction pour ajouter des espaces de remplissage
int	ft_print_padding(int padding)
{
	int	char_count;

	char_count = 0;
	if (padding < 0)
		return (0);
	while (padding-- > 0)
	{
		if (write(1, " ", 1) == -1)
			return (-1);
		char_count++;
	}
	return (char_count);
}
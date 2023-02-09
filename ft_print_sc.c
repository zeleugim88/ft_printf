/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiguele <dmiguele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:37:22 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/09 22:08:07 by dmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s)
{
	int	cont;

	cont = 0;
	if (!s)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[cont])
	{
		if (write (1, &s[cont], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont); //la funcion print devuelve el numero de caracteres impresos
}

int	ft_print_char(int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1); //imprime solo un caracter, la funcion devuelve 1
}

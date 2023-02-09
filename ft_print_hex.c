/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiguele <dmiguele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:28:39 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/09 22:07:52 by dmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nb) //hexadecimal minusculas
{
	int		cont;
	int		sub_ret;
	char	*s;

	cont = 0;
	sub_ret = 0;
	s = "0123456789abcdef";
	if (nb >= 16) //mayor que 16, hay que trozear el numero
	{
		sub_ret = ft_print_hex(nb / 16);
		if (sub_ret == -1)
			return (-1);
		cont = cont + sub_ret;
		sub_ret = ft_print_hex(nb % 16);
		if (sub_ret == -1)
			return (-1);
		cont = cont + sub_ret;
	}
	else
	{
		if (write (1, &s[nb], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}

int	ft_print_hexmay(unsigned int nb) //hexadecimal mayusculas
{
	int		cont;
	int		sub_ret;
	char	*s;

	cont = 0;
	sub_ret = 0;
	s = "0123456789ABCDEF";
	if (nb >= 16)
	{
		sub_ret = ft_print_hexmay(nb / 16);
		if (sub_ret == -1)
			return (-1);
		cont = cont + sub_ret;
		sub_ret = ft_print_hexmay(nb % 16);
		if (sub_ret == -1)
			return (-1);
		cont = cont + sub_ret;
	}
	else
	{
		if (write (1, &s[nb], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}

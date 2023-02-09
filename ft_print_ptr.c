/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiguele <dmiguele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:52:13 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/09 22:07:59 by dmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_print_hexp(unsigned long long nb)
{
	int		cont;
	int		sub_ret;
	char	*s;

	cont = 0;
	sub_ret = 0;
	s = "0123456789abcdef"; //como de 0 a 10, pero de 0 a 16
	if (nb >= 16) //mas de 16, hay que trocear el digito hexadecimal
	{
		sub_ret = ft_print_hexp(nb / 16);
		if (sub_ret == -1)
			return (-1);
		cont = cont + sub_ret;
		sub_ret = ft_print_hexp(nb % 16);
		if (sub_ret == -1)
			return (-1);
		cont = cont + sub_ret;
	}
	else
	{
		if (write (1, &s[nb], 1) == -1) //imprimie la posicion nb en 0123456789abcdef
			return (-1);
		cont++;
	}
	return (cont); //devuelve el tamanyo del numero
}

int	ft_print_ptr(void *p)
{
	int		cont;

	cont = 0;
	if (!p)
		return (ft_putstr("0x0"));
	if (write (1, "0x", 2) == -1)
		return (-1);
	return (ft_print_hexp((unsigned long long) p) + 2);
	//devuelve tamanyo del puntero mas el tamanyo de 0X (2)
}

/*En C, unsigned long long es un tipo de dato de entero sin signo
que ocupa 8 bytes (64 bits) en la memoria. Es un número entero que
puede almacenar valores en el rango de 0 a 18446744073709551615 sin signo.
Es útil cuando se requiere almacenar valores grandes que no sean negativos.*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiguele <dmiguele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:11:52 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/09 22:08:47 by dmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_cifras(long nb) //te calcula el numero de cifras de un numero
{
	int	cifras;

	cifras = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		cifras++;
	}
	return (cifras);
}

static char	*ft_itoa_helper(char *s, int cifras, long m) //funcion apoyo a ITOA
//le pasas un numero, su numero de cifras,
//un puntero a un string y te pasa el numero a string
{
	while (m > 0)
	{
		s[cifras] = '0' + (m % 10); //0 es el caracter 30, asi que suma 30 al numero ascii para convertirlo en caracter
		m = m / 10;
		cifras--;
	}
	return (s);
}

//pasa un entero a string
char	*ft_u_itoa(unsigned int n)
{
	char			*s;
	int				cifras;
	unsigned int	m;

	m = n;
	cifras = ft_cifras(m);
	if (m == 0)
	{
		s = malloc(sizeof(char) * 2);
		if (!s)
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	s = malloc(sizeof(char) * (cifras + 1));
	if (!s)
		return (NULL);
	s[cifras] = '\0';
	cifras--;
	s = ft_itoa_helper(s, cifras, m); //s es el puntero al comienzo del string,
	//string vacio al principio que la funcion ft_mayomen rellena con los numeros caracteres
	return (s);
}

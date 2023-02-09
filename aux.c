/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiguele <dmiguele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:41:37 by dmiguele          #+#    #+#             */
/*   Updated: 2023/02/09 22:07:21 by dmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "ft_printf.h"

int	ft_putstr(char *str) //imprime un string
{
	int	cont;

	cont = 0;
	if (!str)
		return (-1); //
	while (str[cont])
	{
		if (write (1, &str[cont], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}

static int	ft_cifras(long nb) //retorna el numero de cifras de un numero
{
	int	cifras;

	cifras = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		cifras++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		cifras++;
	}
	return (cifras);
}

static char	*ft_mayomen(char *s, int cifras, long m) //funcion apoyo a ITOA
//le pasas un numero, su numero de cifras,
//un puntero a un string y te pasa el numero a string
{
	if (m < 0)
	{
		s[0] = '-';
		m = m * -1;
	}
	while (m > 0)
	{
		s[cifras] = '0' + (m % 10);
		m = m / 10;
		cifras--;
	}
	return (s);
}

char	*ft_itoa(int n) //le pasas un numero (negativo o positivo) y
{
	char	*s;
	int		cifras;
	long	m;

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
	s = ft_mayomen(s, cifras, m);
	return (s);
}
*/

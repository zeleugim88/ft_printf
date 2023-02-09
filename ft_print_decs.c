/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiguele <dmiguele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:57:48 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/09 22:07:43 by dmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_bsten(int nb)
{
	int		cont;
	char	*s;

	cont = 0;
	s = ft_itoa(nb); //para imprimir un numero, hay que pasarlo antes a string
	cont = ft_putstr(s);
	free(s);
	return (cont);
}

int	ft_print_decu(unsigned int nb)
{
	int		cont;
	char	*s;

	cont = 0;
	s = ft_u_itoa(nb); //diferencia con el otro itoa es el tipo de dato, que solo es positivo aqui
	cont = ft_putstr(s);
	free(s);
	return (cont);
}

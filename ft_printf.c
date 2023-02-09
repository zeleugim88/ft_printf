/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiguele <dmiguele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:42:13 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/09 22:08:13 by dmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(va_list lst, char c)
{
	if (c == 'c') //print single caracter
		return (ft_print_char(va_arg(lst, int)));
	else if (c == 's') //print a string of caracters
		return (ft_print_s(va_arg(lst, char *)));
	else if (c == 'p') //print a pointer address
		return (ft_print_ptr(va_arg(lst, void *)));
	else if (c == 'd' || c == 'i') //print integer as decimal number
		return (ft_print_bsten(va_arg(lst, int)));
	else if (c == 'u') //print an unsigned integer as a decimal number
		return (ft_print_decu(va_arg(lst, unsigned int)));
	else if (c == 'x') //print integer as hexadecimal number lowercase
		return (ft_print_hex(va_arg(lst, unsigned int)));
	else if (c == 'X') //print integer as hexadecimal number uppercase
		return (ft_print_hexmay(va_arg(lst, unsigned int)));
	else if (c == '%') //print a literal '%' caracter
	{
		if (write (1, "%", 1) == -1) //verifica si write falla y de paso imprime %
			return (-1);
		return (1);
	}
	return (0);
}

static int	ft_printing(char const *s, va_list lst, int cont, int ret_tot) // funcion apoyo a printf
{ //va_list son todas las variables que van como parametro en la funcion print
//ret_tot es la suma de los caracteres impresos al avanzar en el string y los impresos por cada funcion de imprimir por tipo
	int	sub_ret;

	while (s[cont])
	{
		if (s[cont] == '%' && s[cont + 1]) //en cuanto encuentra %, evalua que va despues
		{
			sub_ret = ft_type(lst, s[cont + 1]); //ft_type reparte a la funcion print correspondiente al tipo de dato
			//devuelve el numero de caracteres impresos
			if (sub_ret == -1)
				return (-1);
			ret_tot = ret_tot + sub_ret; //numbers of characters printed
			cont = cont + 2; //avanza 2 caracteres, incluido el %, ej: %c
		}
		else //avanza por el string hasta que encuentra un %
		{
			if (write (1, &s[cont], 1) == -1)
				return (-1);
			ret_tot++;
			cont++;
		}
	}
	return (ret_tot); //suma total de caracteres impresos: string + variables
}

/*Los tres puntos "..." en una función en C significan "argumentos variables".
Esto significa que la cantidad de argumentos que se pueden pasar a la función
es variable y no se conoce por adelantado.*/
/*Para manejar argumentos variables, se usa la macro va_start,
va_arg y va_end que pertenecen a la biblioteca de C <stdarg.h>.
La macro va_start inicializa el objeto va_list con los argumentos
restantes de la función. La macro va_arg recupera el siguiente argumento
de la lista, y la macro va_end finaliza la lista.*/
int	ft_printf(char const *s, ...)
{
	//printf("Name: %s\n", name1, name2, name3) --> un string que contiene el tipo de dato y un numero de variables indeterminado
	va_list	lst;
	int		cont;
	int		ret_tot;

	va_start(lst, s);
	cont = 0; //cont y ret_tot se pasan como parametro para ahorrar espacio en ft_printing
	ret_tot = 0;
	ret_tot = ft_printing(s, lst, cont, ret_tot);
	va_end(lst);
	return (ret_tot); //printf returns the number of characters printed
}
/*En C, una lista es un tipo de datos que permite almacenar una secuencia
de elementos de diferentes tipos, es decir, permite manejar una colección
de datos con una estructura dinámica. Estas listas se implementan a través
de un tipo de datos especial llamado "va_list". La función "va_start" se
utiliza para inicializar una lista de argumentos y la función "va_arg" se
utiliza para recuperar cada argumento de la lista en un orden determinado.*/

/*
int	main(void)
{
	int				k;
	char			*c;
	char			*d;
	unsigned int	h;
	void			*p;
	int				n;
	int				i;

	k = 65;
	c = "papa";
	d = NULL;
	h = 2394732;
	p = &k;
	n = -214;
	i = 0;
	ft_printf("Esto es un char %c\n", k);
	ft_printf("Esto es un string %s\n", c);
	ft_printf("Esto es un null %s\n", d);
	ft_printf("Esto es un por ciento %%\n");
	ft_printf("esto es una prueba %u\n", -10);
	ft_printf("Esto es un hexadecimal mayuscula %X\n", h);
    ft_printf("Esto es un hexadecimal minuscula %x\n", h);
	ft_printf("Esta es la direccion de un puntero %p\n", p);
	ft_printf("Esto es un decimal %d\n", n);
	ft_printf("Esto es un entero %i\n", i);
	ft_printf("Esto es un puntero %p\n", &c);
	return (0);
}*/

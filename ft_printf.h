/*Un archivo .h es un archivo de cabecera en el lenguaje de programación C.
Contiene declaraciones de constantes, variables y funciones que pueden ser
utilizadas en otros archivos de código fuente. Estos archivos son incluidos
en otros archivos de código fuente mediante la diretiva de preprocesamiento
#include y se compilan junto con ellos para formar un programa completo.*/

// si un archivo de cabecera se ha incluido previamente en el código fuente actual,
//la directiva #ifndef asegura que el contenido del archivo no se vuelva a incluir.
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

// #define SPECIFIERSS "cspdiuxX%"

int		ft_printf(char const *s, ...);
int		ft_print_s(char *s); //
int		ft_print_char(int c); //%s Imprime un solo carácter.
int		ft_print_hex(unsigned int nb); //%x Imprime un número hexadecimal (base 16) en minúsculas.
int		ft_print_hexmay(unsigned int nb); //%X Imprime un número hexadecimal (base 16) en mayúsculas.
int		ft_print_ptr(void *p); //El puntero void * dado como argumento se imprime en formato hexadecimal.
int		ft_print_bsten(int nb);
int		ft_print_decu(unsigned int nb);
int		ft_putstr(char *str);
char	*ft_itoa(int n);
char	*ft_u_itoa(unsigned int n);

#endif

• %i Imprime un entero en base 10.
• %u Imprime un número decimal (base 10) sin signo.
• % % para imprimir el símbolo del porcentaje
%d Imprime un número decimal (base 10).

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmiguele <dmiguele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 16:36:37 by frmurcia          #+#    #+#              #
#    Updated: 2023/02/09 22:07:31 by dmiguele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#archivo de Makefile en Unix que define las reglas para compilar
#un programa llamado "libftprintf.a
# COLORS
GREEN			:= \033[32m
NC				:= \033[m

NAME = libftprintf.a

CC = gcc
SRC = ft_printf.c ft_print_sc.c ft_print_hex.c ft_print_ptr.c ft_print_decs.c ft_u_itoa.c aux.c

FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
HEADER = ft_printf.h

RM = rm -f

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@


$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

re : fclean all

.PHONY = all clean fclean re

#MAGIC VARIABLES
#$@ is target being generated (thing currently being compiled) and is a left-hand side of :
#$< is first prerequisite, the first item on a right-hand side of :
#$^ are all prerequisites, all items on a right-hand side of :

#Most C compilers use -o for the output name and -c to create an object (.o)

#.c --> archivos fuente
#.o --> archivos objeto
#a --> static file. Static libraries (.a): static libraries (which are actually archive files), while reusable in multiple programs, are locked into a program at compile time.
#h --> Header file (libreria)
#Este es un archivo de Makefile en Unix que define las reglas para compilar un programa llamado "libftprintf.a".
#DEFINICION DE VARIABLES
#Las variables GREEN y NC contienen secuencias de escape ANSI para cambiar el color de la salida en la terminal.
#La variable NAME define el nombre del archivo resultante, que es "libftprintf.a".
#La variable CC define el compilador a usar, que es "gcc".
#La variable SRC define una lista de archivos fuente que se compilarán para formar el archivo resultante.
#La variable FLAGS define las banderas que se usarán en la compilación, que son -Wall, -Werror y -Wextra.
#La variable OBJ define una lista de archivos objeto que se crearán a partir de los archivos fuente, y se utiliza en la regla de construcción.
#La variable HEADER define el archivo de cabecera que será incluido en cada archivo fuente durante la compilación.
#La variable RM define el comando para eliminar archivos, que es "rm -f".

#$() llamar a una variable --> para llamar a una variable

#REGLAS / RULES
#“targets : prerequisites
#        recipe
#        …”

#There must be a tab at the beginning of any command
#La regla "%.o : %.c $(HEADER)" define cómo compilar los archivos objeto a partir de los archivos fuente.
#El comando de compilación utiliza el compilador especificado en la variable CC, las banderas en la variable FLAGS y el archivo de cabecera en la variable HEADER.

#La regla "$(NAME) : $(OBJ) $(HEADER)" define cómo crear el archivo resultante a partir de los archivos objeto.
#El comando ar rcs $(NAME) $(OBJ) crea un archivo con el nombre especificado en la variable NAME y los objetos especificados en la variable OBJ.
#Las reglas "all", "clean", "fclean" y "re" definen acciones a realizar cuando se ejecutan los comandos "make all", "make clean", "make fclean" y "make re" respectivamente.
#La regla "all" construye el archivo resultante.
#La regla "clean" elimina los archivos objeto.

#La regla "fclean" elimina los archivos objeto y el archivo resultante, y muestra un mensaje de éxito en la terminal.

#La regla "re" combina "fclean" y "all".

#La línea ".PHONY = all clean fclean re" define que las acciones "all", "clean", "fclean" y "re" son "falsas" (no corresponden a archivos reales), por lo que siempre se ejecutan cuando se invocan a través de "make".*/

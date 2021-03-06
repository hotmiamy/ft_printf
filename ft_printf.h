/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:28:27 by llopes-n          #+#    #+#             */
/*   Updated: 2021/11/18 22:45:32 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

# define HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

int		ft_printf(const char *format, ...);
int		ft_type_c(int chr);
int		ft_type_s(char *str);
int		ft_type_p(unsigned long ptr);
int		ft_type_diu(int nbr, char type);
int		ft_type_x(unsigned int nbr, char type);

#endif

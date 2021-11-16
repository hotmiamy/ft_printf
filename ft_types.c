/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 00:41:55 by llopes-n          #+#    #+#             */
/*   Updated: 2021/11/16 23:42:22 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_c(int chr)
{
	return (write(1, &chr, 1));
}

int	ft_type_s(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, ft_strlen(str) * sizeof(char)));
}

int	ft_type_p(unsigned long ptr)
{
	int		write_len;
	char	*str;
	char	*temp;

	if (ptr == 0 && IS_MACOS == 0)
		return (write(1, "(nil)", 5));
	str = ft_base_converter(ptr, "0123456789abcdef");
	temp = str;
	str = ft_strjoin("0x", temp);
	free(temp);
	write_len = write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (write_len);
}

int	ft_type_diu(int nbr, char flag, char type)
{
	char	*str;
	int		write_len;

	if (nbr == 0)
		return (write(1, "0", 1));
	if (ft_strchr("di", type))
		str = ft_itoa(nbr);
	else
		str = ft_uitoa(nbr);
	if (nbr > 0 && ft_strchr(" +", flag) && flag != '\0' && type != 'u')
		str = flags(str, flag, type);
	write_len = write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (write_len);
}

int	ft_type_x(unsigned int nbr, char flag, char type)
{
	char	*str;
	int		len_write;

	if (nbr == 0)
		return (write(1, "0", 1));
	if (type == 'x')
		str = ft_base_converter(nbr, HEX);
	else
		str = ft_base_converter(nbr, UPPER_HEX);
	if (ft_strchr("#", flag) && ft_strchr("xX", type) && flag != '\0')
		str = flags(str, flag, type);
	len_write = write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (len_write);
}

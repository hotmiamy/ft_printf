/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:05:17 by llopes-n          #+#    #+#             */
/*   Updated: 2021/11/16 23:40:57 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_base_converter(unsigned long nbr, char *base)
{
	int					base_len;
	char				*str;
	unsigned long int	aux;
	int					len;

	aux = nbr;
	base_len = ft_strlen(base);
	len = 0;
	if (nbr == 0)
		len = 1;
	while (aux)
	{
		aux /= base_len;
		len++;
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	while (len--)
	{
		str[len] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (str);
}

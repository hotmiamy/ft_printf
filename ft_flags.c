/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:24:55 by llopes-n          #+#    #+#             */
/*   Updated: 2021/11/14 14:27:30 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flags(char *str, char flag, char type)
{
	char	*temp;

	temp = str;
	if (ft_strchr("diu", type) && ft_strchr(" +", flag))
	{
		if (flag == ' ')
			str = ft_strjoin(" ", temp);
		else
			str = ft_strjoin("+", temp);
		free(temp);
		temp = NULL;
	}
	else if (ft_strchr("xX", type) && flag == '#')
	{
		str = ft_strjoin("0x", temp);
		free(temp);
		temp = NULL;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:24:55 by llopes-n          #+#    #+#             */
/*   Updated: 2021/11/18 22:44:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
		if(type == 'x')
			str = ft_strjoin("0x", temp);
		else 
			str = ft_strjoin("0X", temp);
		free(temp);
		temp = NULL;
	}
	return (str);
}

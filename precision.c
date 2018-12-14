/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:15:07 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/10 10:40:39 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_precision(char *str, t_info **info)
{
	if (str[0] == '.' && str[1] != '*' && str[1] >= '0' && str[1] <= '9')
	{
		(*info)->precision = ft_atoi(str + 1);
		return (ft_strlen(ft_itoa((*info)->precision)) + 1);
	}
	else if (str[0] == '.' && str[1] == '*')
	{
		(*info)->precision = -2;
		return (2);
	}
	else if (str[0] == '.')
	{
		(*info)->precision = 0;
		return (1);
	}
	else
	{
		(*info)->precision = -1;
		return (0);
	}
}

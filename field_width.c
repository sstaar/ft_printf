/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:12:25 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/10 11:36:10 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_field_width(char *str, t_info **info, va_list *ap)
{
	if (str[0] >= '0' && str[0] <= '9')
	{
		(*info)->field_width = ft_atoi(str);
		return (ft_strlen(ft_itoa((*info)->field_width)));
	}
	else if (str[0] == '*')
	{
		(*info)->field_width = va_arg(*ap, int);
		if ((*info)->field_width < 0)
		{
			(*info)->flag[0] = 1;
			(*info)->field_width *= -1;
		}
		return (1);
	}
	else
	{
		(*info)->field_width = -1;
		return (0);
	}
}

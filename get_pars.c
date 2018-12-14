/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:45:05 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/09 18:02:12 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_field_width(va_list *ap, t_info *info)
{
	int		fw;

	fw = info->field_width;
	if (fw == -2)
	{
		fw = va_arg(*ap, int);
		if (fw < 0)
		{
			(info->flag)[0] = 1;
			fw = -fw;
		}
	}
	return (fw);
}

int			get_precision(va_list *ap, t_info *info)
{
	int		pre;

	pre = info->precision;
	if (pre == -2)
		pre = va_arg(*ap, int);
	return (pre);
}

char		get_start_char(t_info *info)
{
	char		c;

	c = '\0';
	if ((info->flag)[2] == 1)
		c = ' ';
	if ((info->flag)[1] == 1)
		c = '+';
	return (c);
}

char		get_padding_char(t_info *info)
{
	char		c;

	c = ' ';
	if ((info->flag)[3] == 1)
		c = '0';
	return (c);
}

int			get_padding_side(t_info *info)
{
	int			side;

	side = 2;
	if ((info->flag)[0] == 1)
		side = 1;
	return (side);
}

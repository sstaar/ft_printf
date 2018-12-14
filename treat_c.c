/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:46:07 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/09 18:02:36 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			treat_c(va_list *ap, t_info *info)
{
	unsigned int	temp;
	int				side;
	int				*fw;

	fw = (int*)malloc(sizeof(int) * 2);
	fw[0] = get_field_width(ap, info);
	fw[1] = 0;
	side = get_padding_side(info);
	if (info->lenght_modifier == 1)
	{
		temp = va_arg(*ap, unsigned int);
		fw[1] = 1;
	}
	else
		temp = (char)va_arg(*ap, unsigned int);
	info->len = ft_padding_char(temp, side, get_padding_char(info), fw);
	return (1);
}

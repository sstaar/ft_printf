/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:59:21 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/09 19:00:04 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		treat_mod(va_list *ap, t_info *info)
{
	intmax_t	nbr;

	if (info->lenght_modifier == 1)
		nbr = va_arg(*ap, long);
	else if (info->lenght_modifier == 2)
		nbr = va_arg(*ap, long long);
	else if (info->lenght_modifier == 6)
		nbr = va_arg(*ap, intmax_t);
	else if (info->lenght_modifier == 7)
		nbr = va_arg(*ap, ssize_t);
	else
	{
		nbr = va_arg(*ap, int);
		if (info->lenght_modifier == 3)
			nbr = (short)nbr;
		else if (info->lenght_modifier == 4)
			nbr = (signed char)nbr;
	}
	return (nbr);
}

int				treat_d(va_list *ap, t_info *info)
{
	int		*sfwp;
	char	*c;

	c = (char*)malloc(sizeof(char) * 2);
	sfwp = (int*)malloc(sizeof(int) * 4);
	sfwp[0] = 2;
	sfwp[1] = get_field_width(ap, info);
	sfwp[2] = get_precision(ap, info);
	c[1] = get_start_char(info);
	c[0] = get_padding_char(info);
	sfwp[0] = get_padding_side(info);
	if (sfwp[1] > sfwp[2])
		sfwp[4] = sfwp[1];
	else
		sfwp[4] = sfwp[2];
	info->len = ft_padding_nbr(treat_mod(ap, info), sfwp, c);
	return (1);
}

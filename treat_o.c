/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:26:50 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/09 11:06:20 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t			treat_mod_u(va_list *ap, t_info *info)
{
	uintmax_t	nbr;

	if (info->lenght_modifier == 1)
		nbr = va_arg(*ap, unsigned long);
	else if (info->lenght_modifier == 2)
		nbr = va_arg(*ap, unsigned long long);
	else if (info->lenght_modifier == 6)
		nbr = va_arg(*ap, uintmax_t);
	else if (info->lenght_modifier == 7)
		nbr = va_arg(*ap, size_t);
	else
	{
		nbr = va_arg(*ap, unsigned int);
		if (info->lenght_modifier == 3)
			nbr = (unsigned short)nbr;
		else if (info->lenght_modifier == 4)
			nbr = (unsigned char)nbr;
	}
	return (nbr);
}

int					treat_ou(va_list *ap, t_info *info, char conv)
{
	int			*par;
	char		c;

	par = (int*)malloc(sizeof(int) * 4);
	par[0] = 0;
	if ((info->flag)[4] == 1 && (conv == 'o' || conv == 'x' || conv == 'X'))
		par[0] = 1;
	par[1] = get_padding_side(info);
	par[2] = get_field_width(ap, info);
	par[3] = get_precision(ap, info);
	c = get_padding_char(info);
	info->len = ft_padding_oct(treat_mod_u(ap, info), par, c, conv);
	return (1);
}

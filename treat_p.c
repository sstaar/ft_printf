/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:15:17 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/09 11:48:51 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		treat_p(va_list *ap, t_info *info)
{
	int		side;
	int		*fw;
	char	*filler;

	filler = (char*)malloc(sizeof(char) * 2);
	fw = (int*)malloc(sizeof(int) * 2);
	filler[1] = ' ';
	side = get_padding_side(info);
	fw[0] = get_field_width(ap, info);
	filler[0] = get_start_char(info);
	filler[1] = get_padding_char(info);
	fw[1] = get_precision(ap, info);
	if (fw[1] > fw[0])
		filler[1] = '0';
	info->len = ft_padding_ptr(va_arg(*ap, unsigned long int),
			side, filler, fw);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 10:23:35 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/09 17:45:28 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		treat_s(va_list *ap, t_info *info)
{
	int		side;
	int		fw;
	int		pre;
	char	*temp;

	if (info->lenght_modifier == 1)
		return (treat_us(ap, info));
	fw = get_field_width(ap, info);
	pre = get_precision(ap, info);
	temp = va_arg(*ap, char*);
	if (!temp)
		temp = "(null)";
	temp = ft_strndup(temp, pre);
	side = get_padding_side(info);
	info->len = ft_padding_str(temp, side, get_padding_char(info), fw);
	free(temp);
	return (1);
}

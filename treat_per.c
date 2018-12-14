/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:46:07 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/10 10:51:12 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_padding_per(int side, char c, int len, char ch)
{
	int i;
	int	counter;

	counter = 0;
	i = -1;
	if (side == 2)
		while (++i < len - 1 && counter++ >= 0)
			ft_putchar(c);
	ft_putchar(ch);
	if (side == 1)
		while (++i < len - 1 && counter++ >= 0)
			ft_putchar(c);
	return (++counter);
}

int			treat_per(va_list *ap, t_info *info, char ch)
{
	int		side;
	int		fw;
	char	c;

	c = get_padding_char(info);
	fw = get_field_width(ap, info);
	side = get_padding_side(info);
	info->len = ft_padding_per(side, c, fw, ch);
	return (1);
}

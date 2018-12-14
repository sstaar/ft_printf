/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_us.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:07:29 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/09 17:44:27 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_padding_ustr(unsigned int *str, int side, char c, int len)
{
	int		i;
	int		size;
	int		counter;

	counter = -1;
	i = -1;
	size = ft_voidlen((unsigned int*)str);
	if (side == 2)
		while (++i < len - size && ++counter >= 0)
			ft_putchar(c);
	counter += ft_putustr(str) + 1;
	if (side == 1)
		while (++i < len - size && ++counter >= 0)
			ft_putchar(c);
	return (counter);
}

unsigned int	*make_null(void)
{
	unsigned int	*temp;

	temp = (unsigned int*)malloc(sizeof(unsigned int) * 7);
	temp[0] = '(';
	temp[1] = 'n';
	temp[2] = 'u';
	temp[3] = 'l';
	temp[4] = 'l';
	temp[5] = ')';
	temp[6] = '\0';
	return (temp);
}

int				treat_us(va_list *ap, t_info *info)
{
	int				side;
	int				fw;
	int				pre;
	unsigned int	*temp;

	fw = get_field_width(ap, info);
	pre = get_precision(ap, info);
	temp = va_arg(*ap, unsigned int*);
	if (!temp)
		temp = make_null();
	temp = ft_voidndup(temp, pre);
	side = get_padding_side(info);
	info->len = ft_padding_ustr(temp, side, get_padding_char(info), fw);
	return (1);
}

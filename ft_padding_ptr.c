/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:16:24 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/09 17:50:48 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_ptr(char *temp, char *c, int *len, int side)
{
	int		counter;

	counter = 0;
	while (side == 2 && c[1] == ' ' && --len[0] >= 0 && counter++ >= 0)
		ft_putchar(c[1]);
	if ((counter += 2) >= 0)
		ft_putstr("0x");
	while (side == 2 && c[1] == '0' && --len[0] >= 0 && counter++ >= 0)
		ft_putchar(c[1]);
	while (--len[1] >= 0 && counter++ >= 0)
		ft_putchar('0');
	ft_putstr(temp);
	counter += ft_strlen(temp);
	while (side == 1 && --len[0] >= 0 && counter++ >= 0)
		ft_putchar(' ');
	return (counter);
}

int			ft_padding_ptr(unsigned long int add, int side, char *c, int *len)
{
	char	*temp;
	int		size;

	temp = ft_putpointer(add);
	if (add == 0)
		temp = ft_strjoin(temp, "0");
	if (add == 0 && len[1] == 0)
		temp = "";
	size = ft_strlen(temp);
	len[1] -= size;
	len[0] -= size + 2;
	if (len[1] > 0)
		len[0] -= len[1];
	return (put_ptr(temp, c, len, side));
}

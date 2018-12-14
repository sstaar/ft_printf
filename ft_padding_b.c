/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:45:53 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/10 13:02:05 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_padding_b(uintmax_t nbr, int *par, char c)
{
	char		*temp;
	size_t		size;

	temp = dic_bin(nbr);
	size = ft_strlen(temp);
	par[3] -= size;
	par[2] -= size;
	if (par[3] >= 0)
		par[2] -= par[3];
	c = ' ';
	par[0] = 0;
	return (put_o(temp, par, c, 'b'));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:09:07 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/10 12:50:18 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*dic_bin(uintmax_t nbr)
{
	char	*temp;

	temp = ft_strnew(1);
	if (nbr == 0)
		temp[0] = '0';
	while (nbr > 0)
	{
		if (nbr % 2 == 1)
			temp = ft_strjoin("1", temp);
		else
			temp = ft_strjoin("0", temp);
		nbr /= 2;
	}
	return (temp);
}

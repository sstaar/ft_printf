/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:05:04 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/09 13:59:38 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			left_one(int *i, char c)
{
	if (--(*i) < 0)
		return (0);
	else
		return (c - '0');
}

char		*add_char(char *nbr1, char *nbr2)
{
	int		i;
	int		j;
	int		left[4];
	char	*temp;

	left[0] = 0;
	temp = ft_strnew(0);
	i = ft_strlen(nbr1);
	j = ft_strlen(nbr2);
	if (i > j)
		left[3] = i;
	else
		left[3] = j;
	while (--left[3] >= 0)
	{
		left[1] = left_one(&i, nbr1[i - 1]);
		left[2] = left_one(&j, nbr2[j - 1]);
		left[0] += left[1] + left[2];
		temp = ft_charjoin((left[0] % 10) + '0', temp, 'l');
		left[0] /= 10;
	}
	if (left[0] > 0)
		temp = ft_charjoin((left[0] % 10) + '0', temp, 'l');
	return (temp);
}

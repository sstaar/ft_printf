/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:37:56 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/10 13:46:16 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*multi1_char(char *nbr1, int nbr2)
{
	int		i;
	char	*temp;

	if (nbr1[0] == '0' || nbr2 == 0)
		return ("0");
	i = -1;
	temp = ft_strdup(nbr1);
	while (++i < nbr2 - 1)
		temp = add_char(temp, nbr1);
	return (temp);
}

char		*multi_char(char *nbr1, char *nbr2)
{
	int			i;
	char		*temp;
	int			j;
	char		*temp1;
	int			t;

	temp = ft_strnew(1);
	temp[0] = '0';
	j = 0;
	i = ft_strlen(nbr2);
	while (--i >= 0)
	{
		t = -1;
		temp1 = multi1_char(nbr1, nbr2[i] - '0');
		while (++t < j)
			temp1 = ft_strjoin(temp1, "0");
		temp = add_char(temp, temp1);
		j++;
	}
	return (temp);
}

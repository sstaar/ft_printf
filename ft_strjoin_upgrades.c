/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_upgrades.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:42:03 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/09 14:06:32 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_charjoin(char c, char *str, char side)
{
	char	*temp;
	char	temp1[2];

	temp1[1] = '\0';
	temp1[0] = c;
	if (side == 'l')
		temp = ft_strjoin(temp1, str);
	else
		temp = ft_strjoin(str, temp1);
	return (temp);
}

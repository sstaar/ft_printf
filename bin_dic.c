/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_dic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:56:03 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/08 13:18:40 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		bin_dic(char *bin, int i)
{
	int		j;
	int		temp;
	int		t;

	t = i;
	j = -1;
	temp = 0;
	while (++j < t)
		temp += (bin[j] - '0') * power_of(2, --i);
	return (temp);
}

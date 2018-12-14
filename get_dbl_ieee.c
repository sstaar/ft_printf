/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dbl_ieee.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:45:46 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/10 13:18:03 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*print_dbl(char *str)
{
	int		i;
	char	*temp;

	temp = ft_strnew(1);
	temp[0] = '1';
	i = 11;
	while (++i < 64)
	{
		temp = multi1_char(temp, 10);
		if (str[i] == '1')
			temp = add_char(temp, power_char("5", i - 11));
	}
	i = bin_dic(str + 1, 11) - 1023;
	if (i >= 0)
		temp = get_all(temp, ft_strlen(temp) - 1, i);
	else
		temp = get_all_neg(temp, ft_strlen(temp) - 1, -i);
	if (str[0] == '1')
		temp = ft_strjoin("-", temp);
	return (temp);
}

char		*get_dbl_ieee(double nbr)
{
	long long	n;
	int			i;
	char		*temp;

	temp = ft_strnew(0);
	i = 63;
	n = *(long long*)(&nbr);
	while (i >= 0)
	{
		if (n >> i & 1)
			temp = ft_strjoin(temp, "1");
		else
			temp = ft_strjoin(temp, "0");
		i--;
	}
	return (print_dbl(temp));
}

char		*print_ldbl(char *str)
{
	int		i;
	char	*temp;

	temp = ft_strnew(1);
	if (str[16] == '1')
		temp[0] = '1';
	else
		temp[0] = '0';
	i = 16;
	while (++i < 80)
	{
		temp = multi1_char(temp, 10);
		if (str[i] == '1')
			temp = add_char(temp, power_char("5", i - 15));
	}
	i = bin_dic(str + 1, 15) - 16383;
	if (i >= 0)
		temp = get_all(temp, ft_strlen(temp) - 1, i);
	else
		temp = get_all_neg(temp, ft_strlen(temp) - 1, -i);
	if (str[0] == '1')
		temp = ft_strjoin("-", temp);
	return (temp);
}

char		*get_ldbl_ieee(long double nbr)
{
	long long	n;
	int			i;
	char		*temp;

	temp = ft_strnew(0);
	i = 79;
	n = *(long long*)(&nbr);
	while (i >= 0)
	{
		if (n >> i & 1)
			temp = ft_strjoin(temp, "1");
		else
			temp = ft_strjoin(temp, "0");
		i--;
	}
	return (print_ldbl(temp));
}

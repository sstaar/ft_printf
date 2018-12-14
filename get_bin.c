/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:53:13 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/09 13:32:27 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fill_bin(char **str, int start, char *src, int *curr)
{
	int		i;

	i = start + 6;
	while (i > start && *curr > 0)
		(*str)[i--] = src[--(*curr)];
	while (i > start)
		(*str)[i--] = '0';
}

char			*four_bytes(char **str)
{
	char		*temp;
	char		*src;
	int			i;
	int			j;

	src = *str;
	i = ft_strlen(src);
	temp = ft_strnew(0);
	temp = ft_strjoin("11110...10......10......10......", temp);
	fill_bin(&temp, 25, *str, &i);
	fill_bin(&temp, 17, *str, &i);
	fill_bin(&temp, 9, *str, &i);
	j = 7;
	while (j > 4 && src[i - 1])
		temp[j--] = src[--i];
	while (j >= 4)
		temp[j--] = '0';
	return (temp);
}

char			*three_bytes(char **str)
{
	char		*temp;
	char		*src;
	int			i;
	int			j;

	src = *str;
	i = ft_strlen(src);
	temp = ft_strnew(0);
	temp = ft_strjoin("1110....10......10......", temp);
	fill_bin(&temp, 17, *str, &i);
	fill_bin(&temp, 9, *str, &i);
	j = 7;
	while (j > 3 && src[i - 1])
		temp[j--] = src[--i];
	while (j >= 3)
		temp[j--] = '0';
	return (temp);
}

char			*two_bytes(char **str)
{
	char		*temp;
	char		*src;
	int			i;
	int			j;

	src = *str;
	i = ft_strlen(src);
	temp = ft_strnew(0);
	temp = ft_strjoin("110.....10......", temp);
	fill_bin(&temp, 9, *str, &i);
	j = 7;
	while (j > 2 && src[i - 1])
		temp[j--] = src[--i];
	while (j >= 2)
		temp[j--] = '0';
	return (temp);
}

int				ft_putuchar(unsigned int i)
{
	char	*temp;
	int		size;

	temp = dic_bin(i);
	size = ft_strlen(temp);
	if (size >= 1 && size <= 7)
		return (ft_putchar(i));
	else if (size >= 8 && size <= 11)
	{
		temp = two_bytes(&temp);
		return (ft_putunichar(temp));
	}
	else if (size >= 12 && size <= 16)
	{
		temp = three_bytes(&temp);
		return (ft_putunichar(temp));
	}
	else if (size >= 17 && size <= 21)
	{
		temp = four_bytes(&temp);
		return (ft_putunichar(temp));
	}
	return (0);
}

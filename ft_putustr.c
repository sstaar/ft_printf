/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putustr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:47:11 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/08 13:22:21 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putustr(unsigned int *str)
{
	int	i;
	int	counter;

	counter = 0;
	i = -1;
	while (str[++i])
		counter += ft_putuchar(str[i]);
	return (counter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:48:38 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/08 13:23:23 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_voidlen(unsigned int *src)
{
	int		i;
	int		counter;

	counter = 0;
	i = -1;
	while (src[++i])
		counter += nbr_bytes(src[i]);
	return (counter);
}

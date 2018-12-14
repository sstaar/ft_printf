/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:06:10 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/10 11:35:50 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	store_flag(t_info **info, int flag)
{
	((*info)->flag)[flag] = 1;
	return (1);
}

int			check_flags(char *str, t_info **info)
{
	if (str[0] == '+')
		return (store_flag(info, 1));
	else if (str[0] == '-')
		return (store_flag(info, 0));
	else if (str[0] == ' ')
		return (store_flag(info, 2));
	else if (str[0] == '0')
		return (store_flag(info, 3));
	else if (str[0] == '#')
		return (store_flag(info, 4));
	else
		return (0);
}

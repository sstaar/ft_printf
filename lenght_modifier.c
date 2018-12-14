/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:19:41 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/10 10:41:19 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			store_lenght_mod(t_info **info, int lm, int ret)
{
	(*info)->lenght_modifier = lm;
	return (ret);
}

int			check_lenght_modifier(char *str, t_info **info)
{
	if (str[0] == 'l' && (!str[1] || str[1] != 'l'))
		return (store_lenght_mod(info, 1, 1));
	else if (str[0] == 'l' && str[1] && str[1] == 'l')
		return (store_lenght_mod(info, 2, 2));
	else if (str[0] == 'h' && (!str[1] || str[1] != 'h'))
		return (store_lenght_mod(info, 3, 1));
	else if (str[0] == 'h' && str[1] && str[1] == 'h')
		return (store_lenght_mod(info, 4, 2));
	else if (str[0] == 'L')
		return (store_lenght_mod(info, 5, 1));
	else if (str[0] == 'j')
		return (store_lenght_mod(info, 6, 1));
	else if (str[0] == 'z')
		return (store_lenght_mod(info, 7, 1));
	else
		return (store_lenght_mod(info, 0, 0));
}

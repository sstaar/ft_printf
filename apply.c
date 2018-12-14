/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:54:02 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/10 12:39:06 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			apply_oux(va_list *ap, t_info *info, char c)
{
	if (c == 'U' || c == 'O' || c == 'B')
	{
		info->lenght_modifier = 1;
		c = c + ('a' - 'A');
	}
	return (treat_ou(ap, info, c));
}

int			apply_difp(va_list *ap, t_info *info, char c)
{
	if (c == 'i' || c == 'd' || c == 'D')
	{
		if (c == 'D')
			info->lenght_modifier = 1;
		return (treat_d(ap, info));
	}
	else if (c == 'f' || c == 'F')
	{
		if (c == 'F')
		{
			c = 'f';
			info->lenght_modifier = 1;
		}
		return (treat_f(ap, info));
	}
	else
		return (treat_p(ap, info));
}

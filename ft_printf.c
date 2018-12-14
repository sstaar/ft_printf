/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:55:05 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/10 11:35:31 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				apply(va_list *ap, char *str, t_info *info)
{
	if (check_difp(str[0]))
		return (apply_difp(ap, info, str[0]));
	else if (str[0] == 's')
		return (treat_s(ap, info));
	else if (str[0] == 'S')
	{
		return (treat_us(ap, info));
	}
	else if (str[0] == 'c')
		return (treat_c(ap, info));
	else if (str[0] == 'C')
	{
		info->lenght_modifier = 1;
		return (treat_c(ap, info));
	}
	else if (check_oux(str[0]))
		return (apply_oux(ap, info, str[0]));
	else
		return (treat_per(ap, info, str[0]));
	return (0);
}

int				treat(va_list *ap, char *str, t_info **info)
{
	int			i;

	i = 0;
	while (str[i] == '-' || str[i] == '+' || str[i] == ' ' ||
			str[i] == '#' || str[i] == '0')
		i += check_flags(str + i, info);
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
		i += check_field_width(str + i, info, ap);
	i += check_precision(str + i, info);
	i += check_lenght_modifier(str + i, info);
	i += apply(ap, str + i, *info);
	return (i);
}

int				work(const char *str, int *i, va_list *ap)
{
	t_info		*info;

	reset_struct(&info);
	(*i) += treat(ap, (char*)(str + *i + 1), &info) + 1;
	return (free_struct(&info));
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			count;

	count = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && !check_if_start(str[i + 1]))
			i++;
		else if (str[i] == '%' && !str[i + 1])
			break ;
		else if (str[i] == '%' && str[i + 1] && check_if_start(str[i + 1]))
			count += work(str, &i, &ap);
		else
		{
			ft_putchar(str[i]);
			count++;
			i++;
		}
	}
	va_end(ap);
	return (count);
}

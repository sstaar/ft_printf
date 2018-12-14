/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:39:20 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/10 10:38:40 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reset_struct(t_info **info)
{
	(*info) = (t_info*)malloc(sizeof(t_info));
	((*info)->flag)[0] = 0;
	((*info)->flag)[1] = 0;
	((*info)->flag)[2] = 0;
	((*info)->flag)[3] = 0;
	((*info)->flag)[4] = 0;
	(*info)->field_width = -1;
	(*info)->precision = -1;
	(*info)->lenght_modifier = 0;
	(*info)->len = 0;
}

int			free_struct(t_info **info)
{
	int		len;

	len = (*info)->len;
	((*info)->flag)[0] = 0;
	((*info)->flag)[1] = 0;
	((*info)->flag)[2] = 0;
	((*info)->flag)[3] = 0;
	((*info)->flag)[4] = 0;
	(*info)->field_width = -1;
	(*info)->precision = -1;
	(*info)->lenght_modifier = 0;
	(*info)->len = 0;
	free(*info);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:49:03 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/10 12:57:16 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_if_start(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f' ||
			c == '#' || c == '+' || c == '-' || c == '0' || c == 'h' ||
			c == 'l' || c == 'L' || (c >= '0' && c <= '9') || c == '.' ||
			c == '*' || c == ' ' || c == 'S' || c == 'C' || c == 'D' ||
			c == 'O' || c == 'U' || c == '%' || c == 'z' ||
			c == 'j' || c == 'F' || c == 'b' || c == 'B')
		return (1);
	else
		return (0);
}

int			check_if_space(char *str)
{
	if (str[1] && str[2] && str[3] && str[4] && str[0] == 's'
			&& str[1] == 'p' &&
			str[2] == 'a' && str[3] == 'c' && str[4] == 'e')
		return (1);
	else
		return (0);
}

int			check_oux(char c)
{
	if (c == 'o' || c == 'u' || c == 'O' || c == 'U' || c == 'x' || c == 'X'
			|| c == 'b' || c == 'B')
		return (1);
	else
		return (0);
}

int			check_difp(char c)
{
	if (c == 'f' || c == 'd' || c == 'D' ||
			c == 'p' || c == 'i' || c == 'F')
		return (1);
	else
		return (0);
}

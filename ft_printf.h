/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:09:12 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/10 12:55:11 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"

typedef struct	s_info
{
	int				flag[5];
	int				field_width;
	int				precision;
	int				lenght_modifier;
	int				len;
}				t_info;

int				ft_printf(const char *str, ...);
void			ft_putnstr(char *str, int n);
void			ft_putnspace(int n);
void			ft_signnbr(int nbr);
void			ft_spacenbr(int nbr);
int				ft_padding_char(unsigned int main, int side, char c, int *len);
int				ft_padding_str(char *str, int side, char c, int len);
int				ft_padding_nbr(intmax_t nbr, int *flag, char *c);
int				ft_padding_ptr(unsigned long int add, int side,
		char *c, int *len);
int				ft_padding_oct(uintmax_t nbr, int *par, char c, char conv);
char			*ft_putoct(uintmax_t nbr);
char			*ft_puthexa(unsigned long long nbr, char c);
char			*ft_putpointer(unsigned long int point);
int				treat_c(va_list *ap, t_info *info);
int				treat_s(va_list *ap, t_info *info);
int				treat_p(va_list *ap, t_info *info);
int				treat_d(va_list *ap, t_info *info);
int				treat_ou(va_list *ap, t_info *info, char conv);
int				treat_f(va_list *ap, t_info *info);
char			*convert_dbl(double nbr);
char			*dic_bin(uintmax_t nbr);
int				bin_dic(char *bin, int i);
char			*get_flt_ieee(float nbr);
char			*add_char(char *nbr1, char *nbr2);
char			*multi_char(char *nbr1, char *nbr2);
char			*multi1_char(char *nbr1, int nbr2);
char			*power_char(char *nbr1, int nbr2);
char			*get_dbl_ieee(double nbr);
char			*get_all(char *str, int ver, int ex);
char			*get_all_neg(char *str, int ver, int ex);
char			*get_ldbl_ieee(long double nbr);
void			reset_struct(t_info **info);
int				ft_putuchar(unsigned int i);
int				ft_putunichar(char *str);
int				ft_putustr(unsigned int *str);
int				ft_voidlen(unsigned int *src);
unsigned int	*ft_voidndup(unsigned int *str, int len);
int				treat_us(va_list *ap, t_info *info);
int				nbr_bytes(unsigned int c);
int				treat_per(va_list *ap, t_info *info, char ch);
int				get_field_width(va_list *ap, t_info *info);
int				get_precision(va_list *ap, t_info *info);
char			get_start_char(t_info *info);
char			get_padding_char(t_info *info);
int				get_padding_side(t_info *info);
char			*ft_charjoin(char c, char *str, char side);
int				check_if_start(char c);
int				check_if_space(char *str);
int				check_oux(char c);
int				check_difp(char c);
int				apply_oux(va_list *ap, t_info *info, char c);
int				apply_difp(va_list *ap, t_info *info, char c);
int				check_flags(char *str, t_info **info);
int				check_field_width(char *str, t_info **info, va_list *ap);
int				check_precision(char *str, t_info **info);
int				check_lenght_modifier(char *str, t_info **info);
int				free_struct(t_info **info);
int				ft_padding_b(uintmax_t nbr, int *par, char c);
int				put_o(char *nbf, int *par, char c, char conv);

#endif

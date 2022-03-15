/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:35:02 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/15 18:29:52 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
#define LIBFT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct s_print
{
	va_list	arg; //argument to print out
	int	width; //
	int	precision; //
	int	zero; //padding with zero only used for numbers
	int	dash; //- it left justifies
	int	pnt; //number of digits to be displayed
	int	hashtag; //add 0x before when used with x X. d/s/c is ignored
	int	space; //insert a space before. when used with + ignore
	int	sign; // pos or neg number
	int	perc; // if it is %
	int	prec_flag;//flag for if precision exist
	int	width_flag;//flag for if width exist
}t_print;

int	ft_isdigit(int c);
int	ft_get_digits_hex(int c);
int	ft_get_digits(long int c);
int	ft_atoi(const char *str);
int	ft_str_count(const char *str);
int	ft_eval_format(t_print *tab, const char *str);
int	ft_strchr_boolean(char c, char *str);
int	ft_strlen(char *str);
int	ft_printf(const char* str, ...);

char	*ft_itoa(long long int d);
char	*ft_itoa_sign(long int d);
char	*ft_str_cut(t_print *tab, char *str);
char	*ft_str_multi_padding_left(char *src, char *padding);
char	*ft_str_padding(t_print *tab, char *src, char padding, int start);
char	*ft_integer_padding(t_print *tab, int s, char padding, int flag);
char	*ft_int_add_char(long long int d, char c);
char	*ft_pf_nbr_hexlow(unsigned int nbr);
char	*ft_pf_nbr_hexup(unsigned int nbr);

t_print	*ft_pf_EvalFlag(t_print *tab, const char c);
t_print	*ft_initialize_flags(t_print *tab);

const char	*ft_width_precision(t_print *tab, const char *str, int flag);

void	ft_update_tab(t_print *tab, const char *str);
void	ft_pf_putchar_width(char c, int size);

int	ft_printchar(t_print *tab);
int	ft_printstr(t_print *tab);
int	ft_printinteger(t_print *tab);
int	ft_printdecimal(t_print *tab);
int	ft_printhex_low(t_print *tab);
int	ft_printhex_up(t_print *tab);

int	ft_pf_putchar(char c);
int	ft_pf_putstr(char *s);
void	ft_pf_putnbr(int n);
void	ft_pf_putnbr_u(unsigned int n);
void	ft_pf_putnbr_hexup(unsigned int nbr);
void	ft_pf_putnbr_hexlow(unsigned int nbr);
void	ft_pf_pointer(void *p);

#endif

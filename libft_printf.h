/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:35:02 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/09 17:02:23 by shabibol         ###   ########.fr       */
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
	int	len; //lenght to be printed
	int	zero; //padding with zero only used for numbers
	int	dash; //- it left justifies
	int	pnt; //number of digits to be displayed
	int	hashtag; //add 0x before when used with x X. d/s/c is ignored
	int	space; //insert a space before. when used with + ignore
	int	sign; // pos or neg number
	int	is_zero; //if it is number zero
	int	perc; // if it is %
}t_print;

void	ft_pf_putchar(char c);
void	ft_pf_putstr(char *s);
void	ft_pf_putnbr_signed(int n);
void	ft_pf_putnbr_unsigned(int n);
void	ft_pf_putnbr_u(unsigned int n);
void	ft_pf_putnbr_hexup(unsigned int nbr);
void	ft_pf_putnbr_hexlow(unsigned int nbr);
void	ft_pf_pointer(void *p);

int	ft_eval_format(va_list arg, const char *str, int i);

t_print	*ft_initialize_flagst(t_print *tab);
t_print	*ft_pf_EvalFlag(t_print *tab, const char *str, int i);
#endif

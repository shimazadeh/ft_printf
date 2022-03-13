/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:39:46 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/13 08:54:02 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_printf.h"

t_print	*ft_pf_EvalFlag(t_print *tab, const char c)
{
	if (c == '-')//left justified
		tab->dash = 1;
	if (c == '.')
		tab->pnt = 1;
	if (c == '#')//
		tab->hashtag = 1;
	if (c == ' ')//padd with space
		tab->space = 1;
	if (c == '%')//print %
		tab->perc = 1;
	if (c == '+')//prefix the integer with its sign
		tab->sign = 1;
	if (c == '0')//padd with zero
		tab->zero = 1;
	return (tab);
}


void	ft_printchar(t_print *tab)//relevant flags: dash (justification), dash makes 0 useless
{
	char	*c;

	if(tab->width && tab->zero && !tab->dash)
		c = ft_padding_left(tab, '0');
	if(tab->width && tab->dash)
		c = ft_padding_left(tab, ' '); //left justified
	else
		c = va_arg(tab->arg, char);
	ft_pf_putchar(c);
}

void	ft_printstr(t_print *tab)//flags: 0, dash, precision & width. # & + & spaceignored when s is used
{
	char	*src;
	char	*res;
	char	*src2;

	src = va_arg(tab->arg, char *);
	src2 = ft_str_cut(tab, src);
	if(tab->width)
	{
		if (!tab->zero && !tab->dash)
			res = ft_str_padding_left(tab, src2, ' ');
		if(tab->zero)
			res = ft_str_padding_left(tab, src2, '0');
		if(tab->dash)
			res = ft_str_padding_right(tab, src2, ' ');
	}
	if(!tab->width)
		res = src2;
	ft_pf_putstr(res);
}

void	ft_printinteger(t_print *tab)//flags: dash, zero, space, sign //0 is ignored with dash
{
	char	*res;
	int		src;
	char	*src2;

	src = va_arg(tab->arg, int);
	if(tab->space)
		src2 = ft_int_add_char(src, ' ');
	if (tab->sign)
		src2 = ft_int_add_char(src, '+');
	if(tab->width)
	{
		if(tab->dash && (tab->space || tab->sign))
			res = ft_str_padding_right(tab, src2, ' ');
		if(tab->dash && !tab->space && !tab->sign)
			res = ft_integer_padding_right(tab, src, ' ');
		if(tab->zero && !tab->space && !tab->sign)
			res = ft_integer_padding_betsign(tab, src, '0');
		if(tab->zero && (tab->space || tab->sign))
			res = ft_str_padding_betsign(tab, src2, '0');
		if(!tab->dash && !tab->zero && (tab->space || tab->sign))
			res = ft_str_padding_left(tab, src2, ' ');
		if(!tab->dash && !tab->zero && !tab->space && !tab->sign)
			res = ft_integer_padding_left(tab, src, ' ');
	}
	if(!tab->width && (tab->sign || tab->space))
		res = src2;
	if(!tab->width && !tab->sign && !tab->space)
		res = ft_itoa(src);
	ft_pf_putstr(res);
}

void	ft_printhex(t_print	*tab)//relevant flags:dash, zero, # 
{
	unsigned int a;

	a = va_arg(tab->arg, unsigned int);
	if(tab->hashtag)
		
	if(tab->width && tab->dash && tab->zero)

	if(tab->width && tab->zero && !tab->dash)
	
	if(tab->hashtag)

}

void	ft_printhex(t_print *tab)
{
	unsigned int a;

	a = va_arg(tab->arg, unsigned int);

}


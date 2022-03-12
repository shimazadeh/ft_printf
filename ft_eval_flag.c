/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:39:46 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/10 22:09:01 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_printf.h"

t_print	*ft_pf_EvalFlag(t_print *tab, const char c)
{
	if (c == '-')//left justified
		tab->dash = 1;
	if (c == '#')//
		tab->hashtag = 1;
	if (c == ' ')//padd with space
		tab->space = 1;
	if (c == '%')//print %
		tab->perc = 1;
	if (c == '+')//prefix the integer with its sign
		tab->sign = 1;
	if (c == 0)//padd with zero
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

void	ft_printstr(t_print *tab)//relevant flag: 0, dash, space. # & + ignored
{
	char	*str;
	
	if(tab->width && !tab->zero && !tab->dash)
		str = ft_str_padding_right(tab, ' ');
	if(tab->width && tab->zero && !tab->dash)
		str = ft_str_padding_right(tab, '0');
	if(tab->width && tab->dash)
		str = ft_str_padding_left(tab, ' ');
	if(tab->width && tab->dash && tab->space)
		str = ft_str_padding_left(tab, ' ');
	if(tab->width && !tab->dash && tab->space)
		str = ft_str_padding_right(tab, ' ');
	else //for when width doesnt exist
	ft_pf_putstr(str);
}

void	ft_printinteger(t_print *tab)//flags: dash, zero, space, sign //0 is ignored with dash
{
	int		src;
	char	*res;

	src = va_arg(tab->arg, int);
	if(tab->width && tab->dash)
		res = ft_padding_integer_righ(tab, ' ');//pad space after the number
	if(tab->width && !tab->dash && tab->zero)// if space exist with this conditions output is the same
		res = ft_integer_padding_betsign(tab, '0');//pad 0 in between the sign and number 
	if(tab->width && !tab->dash && tab->space && !tab->zero)
		res = ft_integer_padding_left(tab, ' ');//pad space before the number
	if(tab->width && tab->dash && tab->space)
		res = ft_integer_padding_right(tab, ' ');//pad space after the number
	if
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


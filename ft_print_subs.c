/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_subs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:21:43 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/14 15:39:54 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_printchar(t_print *tab)//relevant flags: dash. #/0/space/precision underdefined
{
	int		src;
	char	*res;

	src = va_arg(tab->arg, int);
	if(tab->width)
	{
		if(tab->dash)
			res = ft_integer_padding(tab, src, ' ', 2);//pad space to the right
		if(!tab->dash)
			res = ft_integer_padding(tab, src, ' ', 0);//pad space to the left
	}
	if(!tab->width)
		res = ft_itoa(src);
	ft_pf_putstr(res);
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
			res = ft_str_padding(tab, src2, ' ', 0);//pad to the left
		if(tab->zero)
			res = ft_str_padding(tab, src2, '0', 0);//pad to the left
		if(tab->dash)
			res = ft_str_padding(tab, src2, ' ', ft_strlen(src2));//pad to the right
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
			res = ft_str_padding(tab, src2, ' ', ft_strlen(src2));//pad to the right
		if(tab->dash && !tab->space && !tab->sign)
			res = ft_integer_padding(tab, src, ' ', 2);//pad to the right
		if(tab->zero && !tab->space && !tab->sign)
			res = ft_integer_padding(tab, src, '0', 1);//pad between the sign and num
		if(tab->zero && (tab->space || tab->sign))
			res = ft_str_padding(tab, src2, '0', 1);//pad after the first char which is the sign
		if(!tab->dash && !tab->zero && (tab->space || tab->sign))
			res = ft_str_padding(tab, src2, ' ', 0);//pad to the left
		if(!tab->dash && !tab->zero && !tab->space && !tab->sign)
			res = ft_integer_padding(tab, src, ' ', 0);//pad to the left
	}
	if(!tab->width && (tab->sign || tab->space))
		res = src2;
	if(!tab->width && !tab->sign && !tab->space)
		res = ft_itoa(src);
	ft_pf_putstr(res);
}

void	ft_printhex_low(t_print	*tab)//relevant flags:dash, zero, # 
{
	char			*res;
	char			*src2;
	char			*src;

	src = ft_pf_nbr_hexlow(va_arg(tab->arg, unsigned int));
	if (tab->hashtag)
		src2 = ft_str_multi_padding_left(tab, src, "0x");
	if(tab->width)
	{
		if(tab->hashtag && !tab->dash && !tab->zero)
			res = ft_str_padding(tab, src2, ' ', 0);//pad to the left
		if(tab->hashtag && tab->dash)
			res = ft_str_padding(tab, src2, ' ', ft_strlen(src2));//pad to the right
		if(tab->hashtag && tab->zero)
			res = ft_str_padding(tab, src2, '0', 2);//pad after the second char (0x)
		if(!tab->hashtag && tab->zero)
			res = ft_str_padding(tab, src, '0', 0);//pad to the left
		if(!tab->hashtag && tab->dash)
			res = ft_str_padding(tab, src, ' ', 0);//pad to the left
	}
	if(!tab->width && tab->hashtag)
		res = src2;
	if(!tab->width && !tab->hashtag)
		res = src;
	ft_pf_putstr(res);
}

void	ft_printhex_up(t_print	*tab)//relevant flags:dash, zero, #
{
	char			*res;
	char			*src2;
	char			*src;

	src = ft_pf_nbr_hexup(va_arg(tab->arg, unsigned int));
	if (tab->hashtag)
		src2 = ft_str_multi_padding_left(tab, src, "0X");
	if(tab->width)
	{
		if(tab->hashtag && !tab->dash && !tab->zero)
			res = ft_str_padding(tab, src2, ' ', 0);//pad to the left
		if(tab->hashtag && tab->dash)
			res = ft_str_padding(tab, src2, ' ', ft_strlen(src2));//pad to the right
		if(tab->hashtag && tab->zero)
			res = ft_str_padding(tab, src2, '0', 2);//pad after the second char (0x)
		if(!tab->hashtag && tab->zero)
			res = ft_str_padding(tab, src, '0', 0);//pad to the left
		if(!tab->hashtag && tab->dash)
			res = ft_str_padding(tab, src, ' ', 0);//pad to the left
	}
	if(!tab->width && tab->hashtag)
		res = src2;
	if(!tab->width && !tab->hashtag)
		res = src;
	ft_pf_putstr(res);
}

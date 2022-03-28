/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_subs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:21:43 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/28 19:51:56 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(t_print *tab)//relevant flags: dash zero. #/0/space/precision underdefined
{
	char	src;
	char	*src2;
	char	*res;

	src = va_arg(tab->arg, int);
	if (!src)
		src2 = ft_strndup(&src, 0);
	else
		src2 = ft_strndup(&src, 1);
	if (tab->width)
	{
		if (tab->dash)
		{
			if (!src)
				res = ft_char_padding(tab, src2, " ");
			else
				res = ft_str_padding(tab->width, src2, " ", 1);
		}
		if (tab->zero)
			res = ft_str_padding(tab->width, src2, "0", 0);//pad space to the left
		if (!tab->zero && !tab->dash)
			res = ft_str_padding(tab->width, src2, " ", 0);
		free(src2);
		if (!src)
			return (ft_pf_putstr_char_null(tab, res));
		else
			return (ft_pf_putstr_char(res));
	}
	else
		res = src2;
	return (ft_pf_putchar_addr(res));
}

int	ft_printstr(t_print *tab)//flags: 0, dash, precision & width. # & + & spaceignored when s is used
{
	char	*src;
	char	*res;
	char	*src2;

	src = va_arg(tab->arg, char *);
	src2 = ft_str_cut(tab, src);
	if (src == NULL)
	{
		free(src2);
		return (write(1, "(null)", 6));
	}
	if (tab->width)
	{
		if (!tab->zero && !tab->dash)
			res = ft_str_padding(tab->width, src2, " ", 0);//pad to the left
		if (tab->zero)
			res = ft_str_padding(tab->width, src2, "0", 0);//pad to the left
		if (tab->dash)
			res = ft_str_padding(tab->width, src2, " ", ft_strlen(src2));//pad to the right
		free(src2);
	}
	if (!tab->width)
		res = src2;
	return (ft_pf_putstr(res));
}


int	ft_printinteger(t_print *tab)//flags: dash, zero, space, sign //0 is ignored with dash
{
	char	*res;
	int		src;
	char	*src2;
//	char	*src3;

	src = va_arg(tab->arg, int);
//	if (tab->space)
//		src2 = ft_int_add_char(src, ' ');
//	if (tab->sign)
//		src2 = ft_int_add_char(src, '+');
//	if (!tab->space && !tab->sign)
//		src2 = ft_itoa(src);
//	if (tab->pnt == 1)
//		src2 = ft_str_padding_precision(tab, src2, "0", 1);
	src2 = ft_eval_space_sign(tab, src);
	if (tab->width)
	{
		if (tab->dash)
			res = ft_str_padding(tab->width, src2, " ", ft_strlen(src2));//pad to the right
		if (tab->zero && ft_strchr_boolean(*src2, "+-") == 0)
			res = ft_str_padding(tab->width, src2, "0", 0);//pad before the num
		if (tab->zero && ft_strchr_boolean(*src2, "+- ") == 1)
			res = ft_str_padding(tab->width, src2, "0", 1);//pad between the sign and num
		if (!tab->dash && !tab->zero)
			res = ft_str_padding(tab->width, src2, " ", 0);//pad to the left
		free(src2);
	}
	if (!tab->width)
		res = src2;
	return (ft_pf_putstr(res));
}

int	ft_printdecimal(t_print *tab)//flags: dash, zero //space and sign is underdefined
{
	char				*res;
	unsigned int		src;
	char				*src2;

	src = va_arg(tab->arg, unsigned int);
	src2 = ft_itoa(src);
	if (tab->width)
	{
		if (tab->dash)
			res = ft_str_padding(tab->width, src2, " ", ft_strlen(src2));//pad to the right
		if (tab->zero)
			res = ft_str_padding(tab->width, src2, "0", 0);//pad to the left
		if (!tab->dash && !tab->zero)
			res = ft_str_padding(tab->width, src2, " ", 0);//pad to the left
		free(src2);
	}
	if (!tab->width)
		res = src2;
	return (ft_pf_putstr(res));
}
/*
int	ft_printhex_low(t_print	*tab)//relevant flags:dash, zero, # 
{
	char			*res;
	char			*src2;
	char			*src;

	src = ft_pf_nbr_hexlow(va_arg(tab->arg, unsigned int));
	if (tab->hashtag)
		src2 = ft_str_multi_padding_left(src, "0x");
	if (tab->width)
	{
		if (tab->hashtag && !tab->dash && !tab->zero)
			res = ft_str_padding(tab, src2, " ", 0);//pad to the left
		if (tab->hashtag && tab->dash)
			res = ft_str_padding(tab, src2, " ", ft_strlen(src2));//pad to the right
		if (tab->hashtag && tab->zero)
			res = ft_str_padding(tab, src2, "0", 2);//pad after the second char (0x)
		if (!tab->hashtag && tab->zero)
			res = ft_str_padding(tab, src, "0", 0);//pad to the left
		if (!tab->hashtag && tab->dash)
			res = ft_str_padding(tab, src, " ", 0);//pad to the left
	}
	if (!tab->width && tab->hashtag)
		res = src2;
	if (!tab->width && !tab->hashtag)
		res = src;
	return (ft_pf_putstr(res));
}
*/
int	ft_printhex_low(t_print	*tab)//relevant flags:dash, zero, #
{
	char			*res;
	char			*src2;
	char			*src;

	src = ft_pf_nbr_hexlow(va_arg(tab->arg, unsigned int));
	if (tab->hashtag)
	{
		src2 = ft_str_multi_padding_left(src, "0x");
		if (tab->width)
		{
			if (!tab->dash && !tab->zero)
				res = ft_str_padding(tab->width, src2, " ", 0);//pad to the left
			if (tab->dash)
				res = ft_str_padding(tab->width, src2, " ", ft_strlen(src2));//pad to the right
			if (tab->zero)
				res = ft_str_padding(tab->width, src2, "0", 2);//pad after the second char (0x)
		}
		if (!tab->width)
			res = src2;
		free(src2);
	}
	if (!tab->hashtag)
	{
		if (tab->width)
		{
			if (tab->zero)
				res = ft_str_padding(tab->width, src, "0", 0);//pad to the left
			if (tab->dash)
				res = ft_str_padding(tab->width, src, " ", ft_strlen(src));//pad to the left
			if (!tab->dash && !tab->zero)
				res = ft_str_padding(tab->width, src, " ", 0);
		}
		if (!tab->width)
			res = src;
		free(src);
	}
	return (ft_pf_putstr(res));
}
/*
int	ft_printhex_up(t_print	*tab)//relevant flags:dash, zero, #
{
	char			*res;
	char			*src2;
	char			*src;

	src = ft_pf_nbr_hexup(va_arg(tab->arg, unsigned int));
	if (tab->hashtag)
		src2 = ft_str_multi_padding_left(src, "0X");
	if (tab->width)
	{
		if (tab->hashtag && !tab->dash && !tab->zero)
			res = ft_str_padding(tab, src2, " ", 0);//pad to the left
		if (tab->hashtag && tab->dash)
			res = ft_str_padding(tab, src2, " ", ft_strlen(src2));//pad to the right
		if (tab->hashtag && tab->zero)
			res = ft_str_padding(tab, src2, "0", 2);//pad after the second char (0x)
		if (!tab->hashtag && tab->zero)
			res = ft_str_padding(tab, src, "0", 0);//pad to the left
		if (!tab->hashtag && tab->dash)
			res = ft_str_padding(tab, src, " ", 0);//pad to the left
	}
	if (!tab->width && tab->hashtag)
		res = src2;
	if (!tab->width && !tab->hashtag)
		res = src;
	return (ft_pf_putstr(res));
}
*/
int	ft_printhex_up(t_print	*tab)//relevant flags:dash, zero, #
{
	char			*res;
	char			*src2;
	char			*src;

	src = ft_pf_nbr_hexup(va_arg(tab->arg, unsigned int));
	if (tab->hashtag)
	{
		src2 = ft_str_multi_padding_left(src, "0X");
		if (tab->width)
		{
			if (!tab->dash && !tab->zero)
				res = ft_str_padding(tab->width, src2, " ", 0);//pad to the left
			if (tab->dash)
				res = ft_str_padding(tab->width, src2, " ", ft_strlen(src2));//pad to the right
			if (tab->zero)
				res = ft_str_padding(tab->width, src2, "0", 2);//pad after the second char (0x)
		}
		if (!tab->width)
			res = src2;
		free(src2);
	}
	if (!tab->hashtag)
	{
		if (tab->width)
		{
			if (tab->zero)
				res = ft_str_padding(tab->width, src, "0", 0);//pad to the left
			if (tab->dash)
				res = ft_str_padding(tab->width, src, " ", ft_strlen(src));//pad to the left
			if (!tab->dash && !tab->zero)
				res = ft_str_padding(tab->width, src, " ", 0);
		}
		if (!tab->width)
			res = src;
		free(src);
	}
	return (ft_pf_putstr(res));
}

int	ft_printpointer(t_print	*tab)//only width and dash. zero, space, hashtag, sign and precision are underdefined
{
	char			*res;
	char			*src;
	char			*src2;

	src = ft_pf_nbr_hexlow((unsigned long)va_arg(tab->arg, void *));
//	src = ft_str_multi_padding_left(ft_pf_nbr_hexlow((unsigned long)va_arg(tab->arg, void *)), "0x");
	src2 = ft_str_multi_padding_left(src, "0x");
	if (tab->width)
	{
		if (tab->dash)
			res = ft_str_padding(tab->width, src2, " ", ft_strlen(src2));//pad to the right
		if (!tab->dash)
			res = ft_str_padding(tab->width, src2, " ", 0);//pad to the left
		free(src2);
	}
	if (!tab->width)
		res = src2;
	free(src);
	return (ft_pf_putstr(res));
}


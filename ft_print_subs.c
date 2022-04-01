/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_subs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:21:43 by shabibol          #+#    #+#             */
/*   Updated: 2022/04/01 15:29:28 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(t_print *tab)
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
			res = ft_str_padding(tab->width, src2, "0", 0);
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

int	ft_printstr(t_print *tab)
{
	char	*src;
	char	*res;
	char	*src2;

	src = va_arg(tab->arg, char *);
	if (src == NULL && tab->precision == 0)
		src = ft_assign_null("(null)");
	src2 = ft_str_cut(tab, src);
	if (tab->width)
	{
		if (!tab->zero && !tab->dash)
			res = ft_str_padding(tab->width, src2, " ", 0);
		if (tab->zero)
			res = ft_str_padding(tab->width, src2, "0", 0);
		if (tab->dash)
			res = ft_str_padding(tab->width, src2, " ", ft_strlen(src2));
		free(src2);
	}
	if (!tab->width)
		res = src2;
	if (src == NULL)
		free(src);
	return (ft_pf_putstr(res));
}

int	ft_printinteger(t_print *tab)
{
	char	*res;
	int		src;
	char	*src2;

	src = va_arg(tab->arg, int);
	src2 = ft_eval_space_sign(tab, src);
	if (tab->width)
	{
		if (tab->dash)
			res = ft_str_padding(tab->width, src2, " ", ft_strlen(src2));
		if (tab->zero && ft_strchr_boolean(*src2, "+-") == 0)
			res = ft_str_padding(tab->width, src2, "0", 0);
		if (tab->zero && ft_strchr_boolean(*src2, "+- ") == 1)
			res = ft_str_padding(tab->width, src2, "0", 1);
		if (!tab->dash && !tab->zero && tab->pnt == 1)
			res = ft_str_padding(tab->width, src2, " ", 0);
		free(src2);
	}
	if (!tab->width)
		res = src2;
	return (ft_pf_putstr(res));
}

int	ft_printdecimal(t_print *tab)
{
	char	*res;
	char	*src2;
	char	*src3;

	if (tab->pnt == 1)
	{
		src3 = ft_itoa(va_arg(tab->arg, unsigned int));
		if (tab->precision == 0 && src3[0] == '0')
		{
			src2 = (char *)malloc(sizeof(char) * 1);
			src2[0] = '\0';
		}
		else
			src2 = ft_str_padding(tab->precision, src3, "0", 0);
		free (src3);
	}
	else
		src2 = ft_itoa(va_arg(tab->arg, unsigned int));
	if (tab->width)
	{
		if (tab->dash)
			res = ft_str_padding(tab->width, src2, " ", ft_strlen(src2));
		if (tab->zero)
			res = ft_str_padding(tab->width, src2, "0", 0);
		if (!tab->dash && !tab->zero)
			res = ft_str_padding(tab->width, src2, " ", 0);
		free(src2);
	}
	if (!tab->width)
		res = src2;
	return (ft_pf_putstr(res));
}

int	ft_printhex_low(t_print	*tab)
{
	char	*res;
	char	*src;
	char	*src2;

	src = ft_pf_nbr_hexlow(va_arg(tab->arg, unsigned int));
	src2 = ft_eval_hashtag_pnt(tab, src);
	if (tab->width > 0)
	{
		if (!tab->dash && !tab->zero)
			res = ft_str_padding(tab->width, src2, " ", 0);
		if (tab->dash)
			res = ft_str_padding(tab->width, src2, " ", ft_strlen(src2));
		if (tab->zero)
		{
			if (tab->hashtag)
				res = ft_str_padding(tab->width, src2, "0", 2);
			else
				res = ft_str_padding(tab->width, src2, "0", 0);
		}
		free(src2);
	}
	if (!tab->width)
		res = src2;
	return (ft_pf_putstr(res));
}

int	ft_printhex_up(t_print	*tab)
{
	char	*res;
	char	*src;
	char	*src2;

	src = ft_pf_nbr_hexup(va_arg(tab->arg, unsigned int));
	src2 = ft_eval_hashtag_pnt_uppx(tab, src);
	if (tab->width)
	{
		if (!tab->dash && !tab->zero)
			res = ft_str_padding(tab->width, src2, " ", 0);
		if (tab->dash)
			res = ft_str_padding(tab->width, src2, " ", ft_strlen(src2));
		if (tab->zero)
		{
			if (tab->hashtag)
				res = ft_str_padding(tab->width, src2, "0", 2);
			else
				res = ft_str_padding(tab->width, src2, "0", 0);
		}
		free(src2);
	}
	if (!tab->width)
		res = src2;
	return (ft_pf_putstr(res));
}

int	ft_printpointer(t_print	*tab)
{
	char	*res;
	char	*src;
	char	*src2;

	src = ft_pf_nbr_hexlow((unsigned long)va_arg(tab->arg, void *));
	src2 = ft_str_multi_padding_left(src, "0x");
	if (tab->width)
	{
		if (tab->dash)
			res = ft_str_padding(tab->width, src2, " ", ft_strlen(src2));
		if (!tab->dash)
			res = ft_str_padding(tab->width, src2, " ", 0);
		free(src2);
	}
	if (!tab->width)
		res = src2;
	free(src);
	return (ft_pf_putstr(res));
}

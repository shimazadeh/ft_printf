/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 05:40:01 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/12 23:01:44 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_printf.h"

t_print	*ft_initialize_flags(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->dash = 0;
	tab->pnt = 0;
	tab->hashtag = 0;
	tab->space = 0;
	tab->sign = 0;
	tab->is_zero = 0;
//	tab->perc = 0;
	return (tab);
}
/*
int	ft_printf(const char* str , ...)
{
	t_print	*tab;
	int		res;
	va_list	arg;

	tab = (t_print *) malloc (sizeof(t_print));
	if (!tab)
		return (0);
	ft_initialize_flags(tab);
	va_start(tab->arg, str);

	res = 0;
	while (str)
	{
		if (*str == '%')
			ft_initialize_flags(tab);
			res = res + ft_eval_format(tab, str);
		else
		{
			ft_pf_putchar(*str);
			res += res;
		}
		str++;
	}
	va_end(arg);
	return (res);
}
*/

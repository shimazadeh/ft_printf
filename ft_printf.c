/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 05:40:01 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/16 19:23:45 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_printf.h"

t_print	*ft_initialize_flags(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;// -1 is the initialized, 0 meants 0 precision
	tab->zero = 0;
	tab->dash = 0;
	tab->pnt = 0;
	tab->hashtag = 0;
	tab->space = 0;
	tab->sign = 0;
	tab->perc = 0;
	tab->width_flag = 0;
	return (tab);
}
/*
int	ft_eval_format(t_print *tab, const char *str)//to evaluate format
{
	int	i;

	i = 0;
	ft_update_tab(tab, str);
	if (*str == 'd' || *str == 'i')
		i = ft_printinteger(tab);
	if (*str == 'c')
		i = ft_printchar(tab);
	if (*str == 's')
		i = ft_printstr(tab);
	if (*str == 'u')
		i = ft_printdecimal(tab);
	if (*str == 'x')
		i = ft_printhex_low(tab);
	if (*str == 'X')
		i = ft_printhex_up(tab);
//	if (*str == 'p')
//		(unsigned long)va_arg(arg, void *)
	return (i);
}

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
		{
			ft_initialize_flags(tab);
			res = res + ft_eval_format(tab, str);
		}
		else
		{
			ft_pf_putchar(*str);
			res += res;
		}
		str++;
	}
	va_end(arg);
	return (res);
}*/

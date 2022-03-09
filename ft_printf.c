/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 05:40:01 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/09 17:01:17 by shabibol         ###   ########.fr       */
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
	tab->perc = 0;
	return (tab);
}

int	ft_eval_format(t_print *tab, const char *str, int i)
{
	while (str[i] != 'd' || str[i] != 'c' || str[i] != 'u' || str[i] != 'X' || str[i] != 'x' || str[i] != 'p' || str[i] != 's')
	{
		ft_pf_EvalFlag(tab, str, i);
		i++;
	}
	if (str[i] == 'd' || str[i] == 'i')
		ft_printinteger(tab);
	if (str[i] == 'c')
		ft_printchar(tab);
	if (str[i] == 's')
		ft_printstr(tab);
	if (str[i] == 'u')
		ft_pringdecimal(tab);
	if (str[i] == 'x')
		ft_printhex(tab);
	if (str[i] == 'X')
		ft_printhex(tab);
	if (str[i] == 'p')
//		(unsigned long)va_arg(arg, void *)
	return (i);
}

int	ft_printf(const char* str , ...)
{
	t_print	*tab;
	int		i;
	int		res;
	va_list	arg;

	tab = (t_print *) malloc (sizeof(t_print));
	if (!tab)
		return (0);
	ft_initialize_flags(tab);
	va_start(tab->arg, str);

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			res = res + ft_eval_format(tab, str, i + 1);
		else
		{
			ft_pf_putchar(str[i]);
			res += res;
		}
		i++;
	}
	va_end(arg);
	return (res);
}

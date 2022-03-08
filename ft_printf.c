/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 05:40:01 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/08 18:50:37 by shabibol         ###   ########.fr       */
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

int	ft_eval_format(t_print *tab, va_list arg, const char *str, int i)
{
	if (str[i] == 'd' || str[i] == 'i')
		ft_pf_putnbr(va_arg(arg, int));
	if (str[i] == 'c')
		ft_pf_putchar(va_arg(arg, char));
	if (str[i] == 's')
		ft_pf_putstr(va_arg(arg, char *));
	if (str[i] == 'u')
		ft_pf_putnbr_unsigned(va_arg(arg, unsigned int));
	if (str[i] == 'x')
		ft_pf_putnbr_hexlow(va_arg(arg, int));
	if (str[i] == 'X')
		ft_pf_putnbr_hexup(va_arg(arg, int));
	if (str[i] == 'p')
		
	return (i);
}

int	ft_printf(const char* str , ...)
{
	t_print	*tab;
	int		i;
	int		res;

	tab = (t_print *) malloc (sizeof(t_print));
	if (!tab)
		return (0);
	ft_initialize_flags(tab);
	va_list	arg;
	va_start(arg, str);

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			res = res + ft_eval_format(tab, arg, str, i + 1);
		else
		{
			write(1, &str[i], 1);
			res += res;
		}
		i++;
	}
	va_end(arg);
	return (res);
}

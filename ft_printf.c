/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 05:40:01 by shabibol          #+#    #+#             */
/*   Updated: 2022/04/01 15:17:37 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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
	tab->perc = 0;
	tab->width_flag = 0;
	return (tab);
}

int	ft_eval_format(t_print *tab, const char **str)
{
	int	i;

	i = 0;
	ft_update_tab(tab, str);
	if (**str == 'i' || **str == 'd')
		i = ft_printinteger(tab);
	if (**str == 'c')
		i = ft_printchar(tab);
	if (**str == 's')
		i = ft_printstr(tab);
	if (**str == 'u')
		i = ft_printdecimal(tab);
	if (**str == 'x')
		i = ft_printhex_low(tab);
	if (**str == 'X')
		i = ft_printhex_up(tab);
	if (**str == 'p')
		i = ft_printpointer(tab);
	if(**str == '%')
		i = write(1, "%", 1);
	return (i);
}

int	ft_printf(const char *str, ...)
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
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_initialize_flags(tab);
			res = res + ft_eval_format(tab, &str);
		}
		else
			res = res + ft_pf_putchar(*str);
		str++;
	}
	va_end(arg);
	free(tab);
	return (res);
}


#include <stdio.h>
int	main(void)
{
	ft_printf("test1: [%-10.1s]\n", 0);
	printf("test1: [%-10.1s]\n", 0);

	ft_printf("test1: [%-10.2s]\n", 0);
	printf("test1: [%-10.2s]\n", 0);

	ft_printf("test1: [%3.2s]\n", 0);
	printf("test1: [%3.2s]\n", 0);

	ft_printf("test1: [%-10.s]\n", "Shima");
	printf("test1: [%-10.s]\n", "Shima");

	ft_printf("test2: [%-10.15s]\n", "Shima");
	printf("test2: [%-10.15s]\n", "Shima");

	ft_printf("test3: [%-15.10s]\n", "Shima");
	printf("test3: [%-15.10s]\n", "Shima");

	ft_printf("test4: [%-15.10s]\n", "Shima");
	printf("test4: [%-15.10s]\n", "Shima");

	ft_printf("test5: [%-10.s]\n", "Shima");
	printf("test5: [%-10.s]\n", "Shima");

	ft_printf("test6: [%-10.15s]\n", "Shima");
	printf("test6: [%-10.15s]\n", "Shima");

	ft_printf("test7: [%-15.10s]\n", "Shima");
	printf("test7: [%-15.10s]\n", "Shima");

	ft_printf("test8: [%10.s]\n", "Shima");
	printf("test8: [%10.s]\n", "Shima");

	ft_printf("test9: [%10.15s]\n", "Shima");
	printf("test9: [%10.15s]\n", "Shima");

	ft_printf("test10: [%15.10s]\n", "Shima");
	printf("test10: [%15.10s]\n", "Shima");

	ft_printf("test11: [%15.10s]\n", "Shima");
	printf("test11: [%15.10s]\n", "Shima");

	ft_printf("test12: [%10.s]\n", "Shima");
	printf("test12: [%10.s]\n", "Shima");

	ft_printf("test13: [%10.15s]\n", "Shima");
	printf("test13: [%10.15s]\n", "Shima");

	ft_printf("test14: [%15.10s]\n", "Shima");
	printf("test14: [%15.10s]\n", "Shima");

	printf("the end\n");

}

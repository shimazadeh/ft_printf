/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 05:40:01 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/24 14:14:35 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_print	*ft_initialize_flags(t_print *tab)
{
	tab->width = 0;
	tab->precision = -1;
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
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	int i;
	int j;
	int x;
	int y;

	i = ft_printf("p is %05c\n", (char)0);
	j = printf("p is %05c\n", (char)0);
	printf("i is equal to %d, j is equal to %d\n", i, j);

	x = ft_printf("p is %05c\n", 's');
	y = printf("p is %05c\n", 's');
	printf("x is equal to %d, y is equal to %d\n", x, y);
//	printf("printf value of c is: %c", 's');

	i = ft_printf("x is [%%][%x] X is [%%][%X]\n", -42, 42);
	i = ft_printf("x is [%%][%X] X is [%%][%X]\n", -42, 42);
	i = ft_printf("x is [%%][%X] X is [%%][%x]\n", -42, 42);
	i = ft_printf("x is [%%][%X] X is [%%][%x]\n", 42, 42);
	i = ft_printf("x is [%%][%x] X is [%%][%X]\n", 42, 42);
	printf("\ncorrect answer is\n");
	j = printf("x is [%%][%x] X is [%%][%X]", -42, 42);
	printf("\nthe value of i is %d, the value of j is %d\n", i , j);

	printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\n");
	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	i = ft_printf("for null output is:[%5c].", (char)0);
	printf("\n");
	j = printf("for null answer is:[%5c].", (char)0);
	printf("\n");
	printf("the value of i is %d, and j is %d", i, j);

	printf("\n");
	i = ft_printf("for s output is:[%5s].", "sh");
	printf("\n");
	j = printf("for s answer is:[%5s].", "sh");
	printf("\n");
	printf("the value of i is %d, and j is %d", i, j);
	
}*/

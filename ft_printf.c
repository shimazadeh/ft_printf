/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 05:40:01 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/19 19:43:31 by shabibol         ###   ########.fr       */
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

int	ft_eval_format(t_print *tab, const char *str)
{
	int	i;

	i = 0;
	ft_update_tab(tab, str);
	if (*str == 'i' || *str == 'd')
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
	if (*str == 'p')
		i = ft_printpointer(tab);
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
			ft_initialize_flags(tab);
			res = res + ft_eval_format(tab, ++str);
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
	int	i;
	int j;
	void	*src;

	src = "12";
	i = ft_printf("this is a test: %c.", 's');
	printf("\n");
	j = printf("this is a test: %c.", 's');
	printf("\n");
	printf("the value of i is %d, and j is %d", i, j);

//	printf("\n");
//	j = printf("this is a test: %x", 0);
//	printf("the value of i is %d, and j is %d\n", i, j);
//	ft_printf("this is a test: %x", 16);
//	printf("\nthis is a test: %x", 16);
	ft_printf("This is an integer test: %d", 456);
	printf("  correct answer is %d\n", 456);
	ft_printf("This is an integer test: %d", -456);
	printf("  correct answer is %d\n", -456);
	ft_printf("This is an integer test: %d", +1);
	printf("  correct answer is %d\n", +1);
	ft_printf("This is an integer test: %d", -1);
	printf("  correct answer is %d\n", -1);
	ft_printf("This is an integer test: %d", 0);
	printf("  correct answer is %d\n", 0);


	ft_printf("This is an integer test: %s", "SHIMA");
	printf("  correct answer is %s\n", "SHIMA");
	
	ft_printf("This is an integer test: %x", 456);
	printf("  correct answer is %x\n", 456);
	
	ft_printf("This is an integer test: %X", 456);
	printf("  correct answer is %X\n", 456);
	
	ft_printf("This is an integer test: %c", 'c');
	printf("  correct answer is %c\n", 'c');
	
	ft_printf("This is an integer test: %u", 456);
	printf("  correct answer is %u\n", 456);
	
	ft_printf("This is an integer test: %i", 456);
	printf("  correct answer is %i\n", 456);
	return (0);

}
*/
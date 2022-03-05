/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 05:40:01 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/05 12:25:14 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>

char	ft_eval_format(va_list arg, char *str, int i)
{
	if (str[i] == 'd' || str[i] == 'i')
		ft_pf_putnbr(va_arg(arg, int));
	if (str[i] == 'c')
		ft_pf_putchar(va_arg(arg, char));
	if (str[i] == 's')
		ft_pf_putstr(va_arg(arg, char *));
	if (str[i] == 'u')

	if (str[i] == 'x')
		ft_pf_putnbr_hexlow(va_arg(arg, int));
	if (str[i] == 'X')
		ft_pf_putnbr_hexup(va_arg(arg, int));
	if (str[i] == 'p')
		
}

int	ft_printf(const char* str , ...)
{
	int	i;
	int	res;
	va_list	arg;
	va_start(arg, str);

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			res = res + ft_eval_format(arg, str, i + 1);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:46:47 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/12 23:01:41 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
int	ft_isdigit(int c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}

int	ft_str_count(const char *str)
{
	int		size;
	int		j;
	int		i;
	char	*s;

	s = "dcusxX.";
	size = 0;
	i = 0;
	while (str[i])
	{
		j= 0;
		while (s[j])
		{
			if(str[i] == s[j])
				return (size);
			j++;
		}
		size++;
		i++;
	}
	return (size);
}

const char	*ft_width_precision(t_print	*tab, const char *str, int flag)//to store the width and precision in the structure
{
	char	*buff;
	int		result;
	int		j;
	int		size;

	j = 0;
	size = ft_str_count(str);
	buff = (char *) malloc(sizeof(char) * (size + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr_boolean(*str, "dscuxXp."))
	{
		buff[j] = *str;
		str++;
		j++;
	}
	buff[j] = '\0';
	result = ft_atoi(buff);
	if (flag == 0)// means the function is to store width
		tab->width = result;
	else//means the function is to store precision
		tab->precision = result;
	return (str);
}

void	ft_update_tab(t_print *tab, const char *str)
{
	while (!ft_strchr_boolean(*str, "dcusxX"))
	{
		if (ft_isdigit(*str) == 0)
			ft_pf_EvalFlag(tab, *str);
		if (ft_isdigit(*str) == 1)
			str = 	ft_width_precision(tab, str, 0);
		if (*str == '.')
			str = ft_width_precision(tab, ++str, 1);
		str++;
	}
	if (tab->space && tab->sign)//space is ignored in presence of sign
		tab->space = 0;
	if (tab->dash && tab->zero)//zero is ignored in presence of dash
		tab->zero = 0;
}
/*
#include <stdio.h>
int	main(void)
{
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	ft_initialize_flags(tab);
	ft_update_tab(tab, "-0+# %34.15d");
	printf("value of width is %d\n", tab->width);
	printf("value of precision is %d\n", tab->precision);
	printf("zero tag is %d\n", tab->zero);
	printf("dash tag is %d\n", tab->dash);
	printf("space tag is %d\n", tab->space);
	printf("perc tag is %d\n", tab->perc);
	printf("sign tag is %d\n", tab->sign);
	printf("hashtag tag is %d\n", tab->hashtag);
	printf("the answer is %s", "shima");
}
*/
#include <stdio.h>
int	main(int ac, char **av)
{
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	ft_initialize_flags(tab);
	ft_update_tab(tab, av[1]);
	printf("value of width is	%d\n", tab->width);
	printf("value of precision is	%d\n", tab->precision);
	printf("zero tag is		%d\n", tab->zero);
	printf("dash tag is		%d\n", tab->dash);
	printf("space tag is		%d\n", tab->space);
	printf("sign tag is		%d\n", tab->sign);
	printf("hashtag tag is		%d\n", tab->hashtag);
	printf("the answer is	%s", "shima");
}
/*
int	ft_eval_format(t_print *tab, const char *str)//to evaluate format
{
	ft_update_tab(tab, str);
	if (*str == 'd' || *str == 'i')
		ft_printinteger(tab);
	if (*str == 'c')
		ft_printchar(tab);
	if (*str == 's')
		ft_printstr(tab);
	if (*str == 'u')
		ft_pringdecimal(tab);
	if (*str == 'x')
		ft_printhex(tab);
	if (*str == 'X')
		ft_printhex(tab);
	if (*str == 'p')
//		(unsigned long)va_arg(arg, void *)
	return (i);
}*/

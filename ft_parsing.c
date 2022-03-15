/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:46:47 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/15 18:36:30 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

t_print	*ft_pf_EvalFlag(t_print *tab, const char c)
{
	if (c == '-')//left justified
		tab->dash = 1;
	if (c == '.')
		tab->pnt = 1;//precision exist
	if (c == '#')//pad 0x
		tab->hashtag = 1;
	if (c == ' ')//padd with space
		tab->space = 1;
	if (c == '%')//print %
		tab->perc = 1;
	if (c == '+')//prefix the integer with its sign
		tab->sign = 1;
	if (c == '0')//padd with zero
		tab->zero = 1;
	return (tab);
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
		{
			tab->prec_flag = 1;
			str = ft_width_precision(tab, ++str, 1);
		}
		str++;
	}
	if (tab->space && tab->sign)//space is ignored in presence of sign
		tab->space = 0;
	if (tab->dash && tab->zero)//zero is ignored in presence of dash
		tab->zero = 0;
	if (tab->width)
		tab->width_flag = 1;
}
/*
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
*/

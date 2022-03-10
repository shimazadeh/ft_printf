/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:46:47 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/10 21:07:53 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_str_count(const char *str, int start, char *s)
{
	int	size;
	int	j;

	size = 0;
	while (str[start] != '\0')
	{
		j= 0;
		while (s[j] != '\0')
		{
			if(str[start] == s[j])
				return (size);
			j++;
		}
		size++;
		start++;
	}
	return (size);
}

t_print	*ft_width_precision(t_print	*tab, const char *str, int i, int flag)//to store the width and precision in the structure
{
	char	*buff;
	int		result;
	int		j;
	int		size;

	j = 0;
	size = ft_str_count(str, i, "dcusxX.");
	buff = (char *) malloc(sizeof(char) * (size + 1));
	if (!buff)
		return (tab);
	while (str[i] != 'd' || str[i] != 'c' || str[i] != 'u' || str[i] != 's' || str[i] != 'x' || str[i] != 'X' || str[i] != 'p' || str[i] != 's' || str[i] != '.')
	{
		buff[j] = str[i];
		i++;
		j++;
	}
	result = ft_atoi(buff);
	if (flag == 0)// means the function is to store width
		tab->width = result;
	else//means the function is to store precision
		tab->precision = result;
	return (tab);
}

t_print	*ft_update_tab(t_print *tab, const char *str, int i)
{
	if (str[i] != 'd' || str[i] != 'c' || str[i] != 'u' || str[i] != 'X' || str[i] != 'x' || str[i] != 'p' || str[i] != 's')
	{
		while(ft_isdigit(str[i]) == 0)//check if str[i] is not between 1-9
		{
			ft_pf_EvalFlag(tab, str[i]);
			i++;
		}
		if (ft_isdigit(str[i]) == 1)//check if str[i] is between 1-9
			ft_width_precision(tab, str, i, 0);//store the rest of the digits as width
		while (str[i] != '.' || str[i] != 'd' || str[i] != 'c' || str[i] != 'u' || str[i] != 'x' || str[i] != 'X' || str[i] != 's')
			i++;
		if (str[i] == '.')
			ft_width_precision(tab, str, i + 1, 1);//store the rest of the numbers as the precisions
	}
	return (tab);
}

int	ft_eval_format(t_print *tab, const char *str, int i)//to evaluate format
{
	ft_update_tab(tab, str, i);
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

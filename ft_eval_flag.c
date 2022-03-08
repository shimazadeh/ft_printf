/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:39:46 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/08 18:50:40 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_printf.h"

t_print	*ft_pf_EvalFlag(t_print *tab, const char *str, int i)
{
	while (str[i] != 'd' || str[i] != 'c' || str[i] != 'u' || str[i] != 'x' ||str[i] != 'X' || str[i] != 'p' || str[i] != 's')
	{
		if (str[i] == '.')
			tab->pnt = 1;
		if (str[i] == '-')
			tab->dash = 1;
		if (str[i] == 0)
			tab->zero = 1;
		if (str[i] == '#')
			tab->hashtag = 1;
		if (str[i] == ' ')
			tab->space = 1;
		if (str[i] == '%')
			tab->perc = 1;
		if (str[i] == '+')
			tab->sign = 1;
		i++;
	}
	return (tab);
}

int	ft_pf_(t_print *tab, const char *str, int i)
{
	if(tab->zero == 1
}

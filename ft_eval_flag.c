/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:39:46 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/09 21:59:54 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_printf.h"

t_print	*ft_pf_EvalFlag(t_print *tab, const char *str, int i)
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
//	if (ft_isdigit(str[i]) == 1) 
//		tab->width = 1;
	i++;
	return (tab);
}

void	ft_printchar(t_print *tab)//relevant flags: dash (justification)
{
	char	a;

	a = va_arg(tab->arg, int);
	if(tab->width && tab->dash)
		ft_pf_putchar_left(tab->arg); //left justified
	else
		ft_pf_putchar(tab->arg);
}

void	ft_printinteger(t_print *tab)//flags: dash, zero, space, sign
{
	char	a;

	a = va_arg(tab->arg, int);
	if(tab->width && tab->dash)
		ft_right_int(tab, 0);
	if(tab->width && tab->dash)
		ft_left_int(tab, 0);
}

void	ft_printstr(t_print *tab)//relevant flag: #, 0, + is ignored
{
	char	*str;

	str = va_arg(tab->arg, char *);
	if(tab->width && tab->dash)//left justified
		
	else
		ft_pf_putstr(tab->arg);
}

void	ft_printhex(t_print	*tab)//relevant flags:dash, zero, # 
{
	unsigned int a;

	a = va_arg(tab->arg, unsigned int);
	if(tab->hashtag)
		/
	if(tab->width && tab->dash && tab->zero)

	if(tab->width && tab->zero && !tab->dash)
	
	if(tab->hashtag)

}

void	ft_printhex(t_print *tab)
{
	unsigned int a;

	a = va_arg(tab->arg, unsigned int);

}


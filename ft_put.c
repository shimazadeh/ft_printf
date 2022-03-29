/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:54 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/29 19:20:26 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_putchar_addr(char *c)
{
	write(1, c, 1);
	free(c);
	return (1);
}

int	ft_pf_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_pf_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	free(s);
	return (i);
}

int	ft_pf_putstr_char(char *s)
{
	int	i;

	i = 0;
	while (i != ft_strlen(s))
	{
		write(1, &s[i], 1);
		i++;
	}
	free(s);
	return (i);
}

int	ft_pf_putstr_char_null(t_print *tab, char *s)
{
	int	i;

	i = 0;
	while (i != tab->width)
	{
		write (1, &s[i], 1);
		i++;
	}
	free(s);
	return (i);
}

int	ft_get_digit_hex(unsigned long long n)
{
	int	size;

	size = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 16;
		size++;
	}
	return (size);
}

char	*ft_pf_nbr_hexlow(unsigned long long nbr)
{
	char				*result;
	int					digit;
	unsigned long long	num;
	char				*ref;

	ref = "0123456789abcdef";
	num = nbr;
	digit = ft_get_digit_hex(nbr);
	result = (char *)malloc(sizeof(char) * digit + 1);
	if (!result)
		return (NULL);
	if (nbr == 0)
		result[0] = '0';
	result[digit] = '\0';
	while (digit-- && nbr != 0)
	{
		result[digit] = ref[num % 16];
		num = num / 16;
	}
	return (result);
}

char	*ft_pf_nbr_hexup(unsigned int nbr)
{
	char		*result;
	int			digit;
	long int	num;
	char		*ref;

	ref = "0123456789ABCDEF";
	num = nbr;
	digit = ft_get_digit_hex(nbr);
	result = (char *)malloc(sizeof(char) * (digit + 1));
	if (!result)
		return (NULL);
	if (nbr == 0)
		result[0] = '0';
	result[digit] = '\0';
	while (digit-- && nbr != 0)
	{
		result[digit] = ref[num % 16];
		num = num / 16;
	}
	return (result);
}

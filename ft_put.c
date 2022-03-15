/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:54 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/15 18:38:35 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_pf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_pf_putstr(char *s)
{
	int	i;
	
	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write (1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_get_digit_hex(int n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 16;
		size++;
	}
	return(size);
}

char	*ft_pf_nbr_hexlow(unsigned int nbr)
{
	char	*result;
	int		digit;
	long int		num;
	char	*ref;

	ref = "0123456789abcdef";
	num = nbr;
	digit = ft_get_digit_hex(nbr);
	if (nbr <= 0)
	{
		num *= -1;
		digit++;
	}
	result = (char *)malloc(sizeof(char) * (digit + 1));
	if (!result)
		return (NULL);
	while(digit--)
	{
		result[digit] = ref[num % 16];
		num = num / 16;
	}
	if (nbr < 0)
		result[0] = '-';
	return (result);
}

char	*ft_pf_nbr_hexup(unsigned int nbr)
{
	char	*result;
	int		digit;
	long int		num;
	char	*ref;

	ref = "0123456789ABCDEF";
	num = nbr;
	digit = ft_get_digit_hex(nbr);
	if (nbr <= 0)
	{
		num *= -1;
		digit++;
	}
	result = (char *)malloc(sizeof(char) * (digit + 1));
	if (!result)
		return (NULL);
	while(digit--)
	{
		result[digit] = ref[num % 16];
		num = num / 16;
	}
	if (nbr < 0)
		result[0] = '-';
	return (result);
}

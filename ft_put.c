/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:54 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/13 13:40:36 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
/*
void	ft_pf_putchar_width(char c, int size)
{
	int	i;

	i = 0;
	if (size < 0)
		return ;
	while (i <= size)
	{
		write(1, &c, 1);
		i++;
	}
}

void	ft_pf_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_pf_putstr(char *s)
{
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			write (1, &s[i], 1);
			i++;
		}
	}
}

void	ft_pf_putnbr(int n)
{EEEEE
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_pf_putchar('-');
		nbr = nbr + 1;
	}
	if (nbr >= 10)
		ft_pf_putnbr_unsigned(nbr / 10);
	ft_pf_putchar(nbr % 10 + '0');
}

void	ft_pf_putnbr_u(unsigned int n)
{
	if (n >= 10)
		ft_pf_putnbr_u(n / 10);
	ft_pf_putchar(n % 10 + '0');
}


void	ft_pf_putnbr_hexup(unsigned int nbr)
{
	if (nbr >= 16)
		ft_pf_putnbr_hexup(nbr / 16);
	if (nbr % 16 < 16 && nbr % 16 > 9)
		ft_pf_putchar(nbr % 16 + 55);
	else
		ft_pf_putchar(nbr % 16 + '0');
}

void	ft_pf_putnbr_hexlow(unsigned int nbr)
{
	if (nbr >= 16)
		ft_pf_putnbr_hexlow(nbr / 16);
	if (nbr % 16 < 16 && nbr % 16 > 9)
		ft_pf_putchar(nbr % 16 + 87);
	else
		ft_pf_putchar(nbr % 16 + '0');
}
void	ft_pf_pointer(void *p)
{

}
*/
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

#include <stdio.h>
int	main(void)
{
	printf("the real result of 44 is: %010x\n", 44);
/*	printf("the function result of 44 is: %s\n", ft_pf_nbr_hexlow(44));
	printf("the real result of 44 is: %x\n", 456);
	printf("the function result of 44 is: %s\n", ft_pf_nbr_hexlow(456));
	printf("the real result of 44 is: %x\n", 7265);
	printf("the function result of 44 is: %s\n", ft_pf_nbr_hexlow(7265));
	printf("the real result of 44 is: %x\n", 87945);
	printf("the function result of 44 is: %s\n", ft_pf_nbr_hexlow(87945));
	printf("the real result of 44 is: %x\n", 100000);
	printf("the function result of 44 is: %s\n", ft_pf_nbr_hexlow(100000));
*/
}

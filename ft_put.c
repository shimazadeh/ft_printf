/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:24:54 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/13 10:48:48 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
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
/*
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
{
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
char	*ft_pf_nbr_hexlow(unsigned int nbr)
{
	char	*n;
	int		i;

	i = ft_strlen(ft_itoa(nbr));
	n = (char *)malloc(sizeof(char) * ft_strlen(ft_itoa(nbr)));
	while (i >= 0)
	{
		if (nbr >=16)
			ft_pf_nbr_hexlow(nbr / 16);
		if (nbr % 16 < 16 && nbr %  16 > 9)
			n[i] = nbr % 16 + 87;
		else
			n[i] = nbr % 16 + '0';
		i--;
	}
	return (n);
}

#include <stdio.h>
int	main(void)
{
	printf("the real answer for 4: %x\n", 4);
	printf("the function answer for 4: %s\n", ft_pf_nbr_hexlow(4));
	printf("the real answer for 44: %x\n", 44);
	printf("the function answer for 44: %s\n", ft_pf_nbr_hexlow(44));
	printf("the real answer for 654: %x\n", 654);
	printf("the function answer for 654: %s\n", ft_pf_nbr_hexlow(654));
	printf("the real answer for 7895: %x\n", 7895);
	printf("the function answer for 7895: %s\n", ft_pf_nbr_hexlow(7895));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:11:37 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/14 15:39:47 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_printf.h"

int	ft_strchr_boolean(char c, char *str)
{
	while (*str && *str != c)
		str++;
	if (*str == c)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	signed int		result;
	signed int		sign;
	unsigned int	i;
	unsigned int	counter;

	sign = 1;
	i = 0;
	counter = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\t' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	ft_get_digits(int n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*result;
	long int	num;
	size_t		digit;

	num = n;
	digit = ft_get_digits(n);
	if (n <= 0)
	{
		num *= -1;
		digit++;
	}
	result = (char *)malloc(sizeof(char) * (digit + 1));
	if (!result)
		return (NULL);
	result[digit] = '\0';
	while (digit--)
	{
		result[digit] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

char	*ft_itoa_sign(int n)
{
	char		*result;
	long int	num;
	size_t		digit;

	num = n;
	digit = ft_get_digits(n);
	if (n <= 0)
		num *= -1;
	digit++;
	result = (char *)malloc(sizeof(char) * (digit + 1));
	if (!result)
		return (NULL);
	result[digit] = '\0';
	while (digit--)
	{
		result[digit] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		result[0] = '-';
	else
		result[0] = '+';
	return (result);
}

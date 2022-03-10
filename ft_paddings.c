/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:15:51 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/10 22:09:03 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_printf.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
char	*ft_padding_left(t_print *tab, char padding)
{
	char	*dest;
	char	*src;
	int		width;
	int		i;

	i = 0;	
	width = tab->width;
	src = va_arg(tab->arg, char *);
	dest = (char *)malloc(sizeof(char) * (width + 1));
	if (!dest)
		return (NULL);	
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (padding && i != width)
	{
		dest[i] = padding;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_padding_right(t_print *tab, char padding)
{
	char	*dest;
	char	*src;
	int		width;
	int		i;

	i = 0;
	width = tab->width;
	src = va_arg(tab->arg, char *);
	dest = (char *)malloc(sizeof(char) * (width + 1));
	if (!dest)
		return (NULL);
	while (padding && i != (width-ft_strlen(src)))
	{
		dest[i] = padding;
		i++;
	}
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}
*/
int	main(void)
{
//	printf("%s\n", ft_padding_right("Shima", 10, ' '));
//	printf("%s\n", ft_padding_left("Shima", 10, ' '));
	printf("%-40s", "Shima");
}



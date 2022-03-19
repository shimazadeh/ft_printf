/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:15:51 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/19 17:53:26 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_str_cut(t_print *tab, char *str)
{
	char	*dest;
	int		size;
	int		i;

	size = ft_strlen(str);
	i = 0;
//	if (tab->pnt == 0)
//		return (str);
	if (tab->pnt == 1 && tab->precision == 0)
		size = 0;
	if (tab->pnt == 1 && tab->precision != 0)
	{
		if ((tab->precision) < size)
			size = tab->precision;
	}
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (str[i] && i != size)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_str_multi_padding_left(char *src, char *padding)
{
	char	*res;
	int		i;
	int		width;

	width = ft_strlen(src) + ft_strlen(padding);
	i = 0;
	res = (char *)malloc(sizeof(char) *(width + 1));
	if (!res || !padding)
		return (NULL);
	while (padding[i] != '\0')
	{
		res[i] = padding[i];
//		printf("padding is %c\n", padding[i]);
		i++;
	}
//	printf("src before while is %s and i is %d\n", src, i);
	while (src && i < width)
	{
//		printf("src before is %s\n", src);
		res[i] = *src;
//		printf("src after is %s\n", src);
		i++;
		src++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_str_padding(t_print *tab, char *src, char padding, int start)
{
	char	*dest;
	int		i;
	int		width;

	width = tab->width;
	i = 0;
	dest = (char *)malloc(sizeof(char) *(width + 1));
	if (!dest)
		return (NULL);
	while (*src && i != start)
	{
		dest[i++] = *src;
		src++;
	}
	while (padding && i != (width - ft_strlen(src)))
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

char	*ft_int_add_char(long long int d, char c)
{
	int		i;
	char	*dest;
	char	*src;

	i = 1;
	src = ft_itoa(d);
	if (!c || d < 0)
	{
		dest = ft_itoa(d);
		return (dest);
	}
	else
	{
		dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 2));
		dest[0] = c;
		while (*src)
		{
			dest[i] = *src;
			i++;
			src++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

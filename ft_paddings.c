/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:15:51 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/28 19:44:31 by shabibol         ###   ########.fr       */
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
	while (str && i != size)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
char	*ft_str_padding_precision(t_print *tab, char *src, char *padding, int start)
{
	char	*dest;
	int		i;
	int		width;

	width = ft_max_precision(tab, src);
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
		dest[i] = *padding;
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
}*/

char	*ft_eval_space_sign(t_print *tab, int src)
{
	char	*src2;
	if (tab->space)
	{
		src2 = ft_int_add_char(src, ' ');
		if (tab->pnt == 1)
			src2 = ft_str_padding(tab->precision, src2, "0", 1);
	}
	if (tab->sign)
	{
		src2 = ft_int_add_char(src, '+');
		if (tab->pnt == 1)
			src2 = ft_str_padding(tab->precision + 1, src2, "0", 1);
	}
	if (!tab->sign && !tab->space)
	{
		src2 = ft_itoa(src);
		if (tab->pnt == 1)
		{
			if (src < 0)
				src2 = ft_str_padding(tab->precision + 1, src2, "0", 1);
			else
				src2 = ft_str_padding(tab->precision, src2, "0", 0);
		}
	}
	return (src2);
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
		i++;
	}
	while (src && i < width)
	{
		res[i] = *src;
		i++;
		src++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_str_padding(int width, char *src, char *padding, int start)
{
	char	*dest;
	int		i;
	int		final_width;

	final_width = ft_max_width(width, src);
	i = 0;
	dest = (char *)malloc(sizeof(char) *(final_width + 1));
	if (!dest)
		return (NULL);
	while (*src && i != start)
	{
		dest[i++] = *src;
		src++;
	}
	while (padding && i != (final_width - ft_strlen(src)))
	{
		dest[i] = *padding;
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

char	*ft_char_padding(t_print *tab, char *src, char *padding)
{
	char	*dest;
	int		i;
	int		width;

	width = ft_max_width(tab->width, src);
	i = 1;
	dest = (char *)malloc(sizeof(char) *(width + 1));
	if (!dest)
		return (NULL);
	dest[0] = *src;
	while (padding && i != width + 1)
	{
		dest[i] = *padding;
		i++;
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
//	src = ft_itoa(d);
	if (!c || d < 0)
	{
//		dest = ft_itoa(d);
		return (ft_itoa(d));
	}
	else
	{
		src = ft_itoa(d);
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

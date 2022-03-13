/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:15:51 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/13 13:56:41 by shabibol         ###   ########.fr       */
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

char	*ft_str_cut(t_print *tab, char *str)//cutes the string with respect to precision
{
	char	*dest;
	int		size;

	size = ft_strlen(str);
	if(tab->prec_flag == 1 && tab->precision == 0)//meaning there is a dot but no numb
	{
		size = 0;
		return (NULL);
	}
	else if (tab->prec_flag == 1 && tab->precision == 1)// there is a dot and numb
	{
		if ((tab->precision) < size)
			size = tab->precision;
	}
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while(str[size])
	{
		dest[size] = str[size];
		size--;
	}
	return (dest);
}


char	*ft_str_padding_right(t_print *tab, char *src, char padding)//pad a character to the right of the string
{
	char	*dest;
	int		i;
	int		width;

	i = 0;
	width = tab->width;
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

char	*ft_str_padding_left(t_print *tab, char *src, char padding)//pad a character tp the left of the string
{
	char	*dest;
	int		i;
	int		width;

	i = 0;
	width = tab->width;
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

char	*ft_str_padding_betsign(t_print *tab, char *src, char padding)
{
	char	*dest;
	int		i;
	int		width;

	width = tab->width;
	i = 0;
	dest = (char *)malloc(sizeof(char) *(width + 1));
	if(!dest)
		return(NULL);
	if(*src == '-' || *src == '+' || *src == ' ')
	{
		dest[i++] = *src;
		src++;
	}
	while(padding && i != (width - ft_strlen(src)))
	{
		dest[i] = padding;
		i++;
	}
	while(*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return(dest);
}

char	*ft_str_multi_padding_left(t_print *tab, char *src, char *padding)
{
	char	*dest;
	int		i;
	int		width;

	width = ft_strlen(src) + ft_strlen(padding);
	i = 0;
	dest = (char *)malloc(sizeof(char) *(width + 1));
	if(!dest)
		return(NULL);
	while(padding[i])
	{
		dest[i] = padding[i];
		i++;
	}
	while(*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return(dest);
}

char	*ft_str_padding_bet0x(t_print *tab, char *src, char padding)
{
	char	*dest;
	int		i;
	int		width;

	width = tab->width;
	i = 2;
	dest = (char *)malloc(sizeof(char) *(width + 1));
	if(!dest)
		return(NULL);
	while(*src == '-' || *src == 'x' || *src == 'X')
	{
		dest[i++] = *src;
		src++;
	}
	while(padding && i != (width - ft_strlen(src) + 2))
	{
		dest[i] = padding;
		i++;
	}
	while(*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return(dest);
}

char	*ft_integer_padding_betsign(t_print *tab, int s, char padding)//pad a character in between the sign and the number
{
	char	*dest;
	char	*src;

	src = ft_itoa(s);
	dest = ft_str_padding_betsign(tab, src, padding);
	return (dest);
}

char	*ft_integer_padding_left(t_print *tab, int s, char padding)//pads a character to the left of the number
{
	char	*dest;
	char	*src;

	src = ft_itoa(s);
	dest = ft_str_padding_left(tab, src, padding);
	return (dest);
}

char	*ft_integer_padding_right(t_print *tab, int s, char padding)//pads a character to the right of the number
{
	char	*dest;
	char	*src;

	src = ft_itoa(s);
	dest = ft_str_padding_right(tab, src, padding);
	return (dest);
}

/*char	*ft_int_add_sign(int d)
{
	char	*str;

	if (d >= 0)
		str = ft_itoa_sign(d);
	else
		str = ft_itoa(d);
	return(str);
}*/

char	*ft_int_add_char(int d, char c)
{
	int		i;
	char	*dest;
	char	*src;

	i = 1;
	src = ft_itoa(d);
	if (d < 0)
	{
		dest = ft_itoa(d);
		return (dest);
	}
	else
	{
		dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 2));
		dest[0] = c;
		while(src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

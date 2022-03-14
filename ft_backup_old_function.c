/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_old_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:31:33 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/14 15:00:49 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

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
	while(*src == '0' || *src == 'x' || *src == 'X')
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

char	*ft_int_add_sign(int d)
{
	char	*str;

	if (d >= 0)
		str = ft_itoa_sign(d);
	else
		str = ft_itoa(d);
	return(str);
}

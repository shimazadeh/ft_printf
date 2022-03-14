/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_old_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:31:33 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/14 19:37:14 by shabibol         ###   ########.fr       */
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


void	ft_printinteger(t_print *tab)//flags: dash, zero, space, sign //0 is ignored with dash
{
	char	*res;
	int		src;
	char	*src2;

	src = va_arg(tab->arg, int);
	if(tab->space)
		src2 = ft_int_add_char(src, ' ');
	if (tab->sign)
		src2 = ft_int_add_char(src, '+');
	if(tab->width)
	{
		if(tab->dash && (tab->space || tab->sign))
			res = ft_str_padding(tab, src2, ' ', ft_strlen(src2));//pad to the right
		if(tab->dash && !tab->space && !tab->sign)
			res = ft_integer_padding(tab, src, ' ', 2);//pad to the right
		if(tab->zero && !tab->space && !tab->sign)
			res = ft_integer_padding(tab, src, '0', 1);//pad between the sign and num
		if(tab->zero && (tab->space || tab->sign))
			res = ft_str_padding(tab, src2, '0', 1);//pad after the first char which is the sign
		if(!tab->dash && !tab->zero && (tab->space || tab->sign))
			res = ft_str_padding(tab, src2, ' ', 0);//pad to the left
		if(!tab->dash && !tab->zero && !tab->space && !tab->sign)
			res = ft_integer_padding(tab, src, ' ', 0);//pad to the left
	}
	if(!tab->width && (tab->sign || tab->space))
		res = src2;
	if(!tab->width && !tab->sign && !tab->space)
		res = ft_itoa(src);
	ft_pf_putstr(res);
}

char	*ft_integer_padding(t_print *tab, int s, char padding, int flag)//pad a character to the int depending on the flag
{
	char	*dest;
	char	*src;

	src = ft_itoa(s);
	if (flag == 1)//between the first char and the number
		dest = ft_str_padding(tab, src, padding, 1);
	if (flag == 0)//to the left of the number
		dest = ft_str_padding(tab, src, padding, 0);
	if (flag == 2)//to the right of the number
		dest = ft_str_padding(tab, src, padding, ft_strlen(src));
	return (dest);
}



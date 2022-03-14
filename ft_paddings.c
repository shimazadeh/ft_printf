/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:15:51 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/14 19:59:19 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_printf.h"
#include <stdio.h>

char	*ft_str_cut(t_print *tab, char *str)//cutes the string with respect to precision
{
	char	*dest;
	int		size;

	size = ft_strlen(str);
	if(tab->prec_flag == 1 && tab->precision == 0)//meaning there is a dot but no numb
		return (NULL);
	if (tab->prec_flag == 1 && tab->precision != 0)// there is a dot and numb
	{
		if ((tab->precision) < size)
			size = tab->precision;
	}
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while(str[size - 1])
	{
		dest[size - 1] = str[size - 1];
		size--;
	}
	return (dest);
}

char	*ft_str_multi_padding_left(t_print *tab, char *src, char *padding)
{
	char	*dest;
	int		i;
	int		width;

	width = ft_strlen(src) + ft_strlen(padding);
	i = 0;
	dest = (char *)malloc(sizeof(char) *(width + 1));
	if(!dest || !padding)
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

char	*ft_str_padding(t_print *tab, char *src, char padding, int start)//start is the starting position to padd. 0 means before the string , 1 mean after the first character
{
	char	*dest;
	int		i;
	int		width;

	width = tab->width;
	i = 0;
	dest = (char *)malloc(sizeof(char) *(width + 1));
	if(!dest)
		return(NULL);
	while(*src && i != start)
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

char	*ft_int_add_char(long int d, char c)
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
		while(*src)
		{
			dest[i] = *src;
			i++;
			src++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

int	main(int ac, char **av)
{
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	ft_initialize_flags(tab);
	tab->width = 10;
	tab->precision = 0;
	tab->prec_flag = 1;
//	printf("the value of precision is:%d and flag is: %d\n", tab->precision, tab->prec_flag);
//	printf("cutting based on precision test:%s\n", ft_str_cut(tab, "SHIMA"));
	printf("test:%u\n", 23);

/*	printf("multipadding test: %s\n", ft_str_multi_padding_left(tab, "1234", "0x"));
	printf("multipadding test: %s\n", ft_str_multi_padding_left(tab, "1", "0x"));
	printf("multipadding test: %s\n", ft_str_multi_padding_left(tab, "-1234", "0x"));
	printf("multipadding test: %s\n", ft_str_multi_padding_left(tab, " 1234", "0"));
	printf("addchar test: %s\n", ft_int_add_char(-1234, '+'));
	printf("addchar test: %s\n", ft_int_add_char(-1234, '-'));
	printf("addchar test: %s\n", ft_int_add_char(-1234, ' '));
	printf("addchar test: %s\n", ft_int_add_char(-1234, '\0'));

	printf("test1 :%s\n", ft_str_padding(tab, "SHIMA", '0', 0));
	printf("test2 :%s\n", ft_str_padding(tab, "SHIMA", '0', 1));
	printf("test3 :%s\n", ft_str_padding(tab, "SHIMA", '0', 2));
	printf("test4 :%s\n", ft_str_padding(tab, "SHIMA", '0', 3));
	printf("test5 :%s\n", ft_str_padding(tab, "SHIMA", '0', 4));
	printf("test6 :%s\n", ft_str_padding(tab, "SHIMA", '0', 5));
	printf("test6 :%s\n", ft_str_padding(tab, "", '0', 5));

	printf("test6 :%s\n", ft_integer_padding(tab, 1234, '0', 0));
	printf("test6 :%s\n", ft_integer_padding(tab, 1234, '0', 1));
	printf("test6 :%s\n", ft_integer_padding(tab, 1234, '0', 2));
	
	printf("test6 :%s\n", ft_integer_padding(tab, 1 , '0', 0));
	printf("test6 :%s\n", ft_integer_padding(tab, 1 , '0', 1));
	printf("test6 :%s\n", ft_integer_padding(tab, 1 , '0', 2));

	printf("test6 :%s\n", ft_integer_padding(tab, -1234, '0', 0));
	printf("test6 :%s\n", ft_integer_padding(tab, -1234, '0', 1));
	printf("test6 :%s\n", ft_integer_padding(tab, -1234, '0', 2));
*/
}

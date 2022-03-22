/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_function_partII.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:18:03 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/22 14:45:17 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strndup(char	*src, int size)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(sizeof(char) * (size + 1));
	if (s2 == NULL)
		return (NULL);
	while (s2 && i != size)
	{
		s2[i] = src[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
/*
char	*ft_set_null(char *src)
{
	char	*dest;
	char	*ref;
	int		i;

	i = 0;
	ref = "(null)";
	dest = malloc(sizeof(char) * 7);
	while (ref[i])
	{
		dest[i] = ref[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}*/

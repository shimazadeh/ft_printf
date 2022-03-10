#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_padding_left(char *str, int width, char padding)
{
	char	*dest;
	int		i;

	i = 0;	
	dest = (char *)malloc(sizeof(char) * (width + 1));
	if (!dest)
		return (NULL);	
	while (str[i])
	{
		dest[i] = str[i];
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

char	*ft_padding_right(char	*str, int width, char padding)
{
	char	*dest;
	int		i;

	i = 0;	
	dest = (char *)malloc(sizeof(char) * (width + 1));
	if (!dest)
		return (NULL);	
	while (padding && i != (width-ft_strlen(str)))
	{
		dest[i] = padding;
		i++;
	}
	while (*str)
	{
		dest[i] = *str;
		i++;
		str++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	printf("%s\n", ft_padding_right("Shima", 10, ' '));
	printf("%s\n", ft_padding_left("Shima", 10, ' '));
	printf("%d\n", ft_strlen("Shima"));
}



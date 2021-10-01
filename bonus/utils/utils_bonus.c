#include "../minitalk_bonus.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static int	ft_neg(char c)
{
	int	i;

	i = 0;
	if (c >= 0)
		return (1);
	while (c < 0)
	{
		c = c << 1;
		i++;
	}
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;
	int	count;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		count = ft_neg(s[i]);
		write(1, &s[i], count);
		i += count;
	}
}

void	ft_putendl(char *s)
{
	ft_putstr(s);
	write(1, "\n", 1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	dim1;
	size_t	dim2;

	i = 0;
	j = 0;
	dim1 = ft_strlen((char *)s1);
	dim2 = ft_strlen((char *)s2);
	str = (char *)malloc((sizeof(char)) * (dim1 + dim2 + 1));
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

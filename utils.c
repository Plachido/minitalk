#include "minitalk.h"


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

static int	ft_dim(int n)
{
	int	dim;

	dim = 0;
	if (n <= 0)
	{
		dim++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		dim++;
	}
	return (dim);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	size_t	i;

	nb = n;
	if (nb < 0)
		nb = -nb;
	i = ft_dim(n);
	str = (char *)malloc((sizeof(char)) * (i + 1));
	if (!str)
		return (0);
	*(str + i--) = 0;
	while (nb > 0)
	{
		*(str + i--) = nb % 10 + '0';
		nb /= 10;
	}
	if (i == 0 && str[1] == '\0')
		*(str + i) = '0';
	else if (i == 0 && str[1] != '\0')
		*(str + i) = '-';
	return (str);
}






static int ft_neg(char c)
{
	int i;

	i = 0;
	if (c >= 0)
		return 1;
	while (c < 0)
	{
		write(1, "e", 1);
		c = c << 1;
		i++;
	}
	return(i);
}


void	ft_putstr(char *s)
{
	int i;
	int count;

	if (!s)
		return ;
	i = 0;
	while(s[i])
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


static int	ft_control_ws(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	return (i);
}



int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	res;

	i = 0;
	s = 1;
	res = 0;
	i = ft_control_ws(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = ((res * 10) + (str[i++] - '0'));
		if (res > 2147483648)
			break ;
	}
	if ((res == 2147483648 && s == -1) || res <= 2147483648)
		return (res * s);
	if (s == 1)
		return (-1);
	return (0);
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
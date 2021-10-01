#include "../minitalk_bonus.h"

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

#include "../minitalk_bonus.h"

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

#include "minitalk.h"

static void	ft_endchr(char *s)
{
	static int	flag;

	if (!flag)
	{
		ft_putendl(s);
		flag = 1;
	}
	else
	{
		kill(ft_atoi(s), SIGUSR1);
		flag = 0;
	}
}

static void	ft_create_string(int sig)
{
	static char	c[2];
	static char	*s;
	static int	count;
	char		*tmp;

	c[0] = c[0] << 1;
	if (sig == SIGUSR2)
		c[0] += 1;
	if (++count == 8)
	{
		tmp = s;
		s = ft_strjoin(s, c);
		free(tmp);
		if (!c[0])
		{
			ft_endchr(s);
			free(s);
			s = NULL;
		}
		c[0] = 0;
		count = 0;
	}
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	ft_putendl(pid);
	free(pid);
	signal(SIGUSR1, ft_create_string);
	signal(SIGUSR2, ft_create_string);
	while (1)
		pause();
}

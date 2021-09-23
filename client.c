#include "minitalk.h"

static void	ft_sendc(pid_t pid, char c)
{
	int	i;

	i = 8;
	while (--i)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
	}
	if (c & 1)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	usleep(50);
}

static void	confirm(int sig)
{
	ft_putendl("Message received");
	exit(0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*cpid;
	pid_t	pid;

	signal(SIGUSR1, confirm);
	i = -1;
	pid = ft_atoi(argv[1]);
	cpid = ft_itoa(getpid());
	while (argv[2][++i])
		ft_sendc(pid, argv[2][i]);
	ft_sendc(pid, '\0');
	i = -1;
	while (cpid[++i])
		ft_sendc(pid, cpid[i]);
	ft_sendc(pid, '\0');
	while (1)
		pause();
}

#include "minitalk.h"

static void	ft_sendc(pid_t pid, char c)
{
	int i;
	i = 8;

	while (--i)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(5000);
	}
	if (c & 1)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
}


int main(int argc, char **argv)
{
	pid_t pid;
	int i;

	i = -1;
	pid = ft_atoi(argv[1]);
	while (argv[2][++i])
		ft_sendc(pid, argv[2][i]);
	ft_sendc(pid, '\0');
}
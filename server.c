#include "minitalk.h"

static void ft_create_string(int sig)
{
	static char c[2];
	static char *s;
	static int count;
	char		*tmp;

	c[0] = c[0] << 1;
	if (sig == SIGUSR2)
		c[0] += 1;
	if (++count == 8)
	{
		tmp = s;
		s = ft_strjoin(s, c);
		free(tmp);
		if (c[0] == '\0')
		{
			ft_putendl(s);
			free(s);
			s = NULL;
		}
		c[0] = 0;
		count = 0;
	}
}

int main()
{
	int pid;

	pid = (int)getpid();
	ft_putendl(ft_itoa(pid));
	signal(SIGUSR1, ft_create_string);
	signal(SIGUSR2, ft_create_string);
	while(1)
		pause();
}

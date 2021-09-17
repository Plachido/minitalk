#include "minitalk.h"

int main()
{
	int pid;

	pid = (int)getpid();
	ft_putendl(ft_itoa(pid));
	return(0);
}

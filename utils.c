#include "so_long.h"
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}	
}

void    ft_putnbr_fd_positive(int n)
{
    char    c;

    if (n > 9)
        ft_putnbr_fd_positive(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}
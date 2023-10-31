#include <unistd.h>

void	ft_putnbr(int n)
{
	char	str[10] = "0123456789";

	if (n < 10)
		write(1, &str[n],1);
	else
	{
		ft_putnbr(n/10);
		write(1, &str[n % 10], 1);
	}

}

int	main(int argc, char *argv[])
{
	int	n;

	n = 0;
	while(n <= 100)
	{
		if (n % 3 == 0 && n % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (n % 3 == 0)
			write(1, "fizz", 4);
		else if (n % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(n);
		write(1, "\n", 1);
		n++;
	}
}
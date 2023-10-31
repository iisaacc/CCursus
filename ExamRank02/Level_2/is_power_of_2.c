#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return(0);
	while (n % 2 == 0)
		n /= 2;
	if (n == 1)
		return (1);
	else
		return (0);
}

	int main()
	{
		int	n;

		n = 1073741823;
		printf("%d \n",is_power_of_2(n));
	}
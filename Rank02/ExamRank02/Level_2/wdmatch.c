#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int main (int argc, char *argv[])
{
	int	i;
	int	i2;
	int	len;

	len = 0;
	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			while(argv[2][i2])
			{
				if (argv[1][i] == argv[2][i2])
				{
					len++;
					break;
				}
				i2++;
			}
			i++;
		}
		if (len == ft_strlen(argv[1]))
		{
			i = 0;
			while (argv[1][i])
			{
				write(1, &argv[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
}



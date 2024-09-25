#include <unistd.h>

int main(int argc, char *argv[])
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 65 && argv[1][i] <= 90)
				argv[1][i] = (argv[1][i] - 'A' + 13) % 26 + 'A';
			if (argv[1][i] >= 97 && argv[1][i] <= 122)
				argv[1][i] = (argv[1][i] - 'a' + 13) % 26 + 'a';
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}
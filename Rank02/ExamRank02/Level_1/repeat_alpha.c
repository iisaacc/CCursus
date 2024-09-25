	#include <unistd.h>

int main(int argc, char *argv[])
{
	int	i;
	int	r;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			r = 0;
			if (argv[1][i] >= 65 && argv[1][i] <= 90)
				r = argv[1][i] - 'A';
			if (argv[1][i] >= 97 && argv[1][i] <= 122)
				r = argv[1][i] - 'a';
			while (r >= 0)
				{
					write(1, &argv[1][i], 1);
					r--;
				}
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
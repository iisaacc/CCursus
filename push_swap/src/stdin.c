#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		size_t	bytes_read;
		size_t	bufsize = 3; // Tamaño inicial del búfer
		char	buffer[bufsize + 1];
		char	*str = NULL;
		int		boole;

		buffer[bufsize] = 0;
		write(1, "Introduce un argumento: ",24);
		bytes_read = 1;
		boole = 0;
		while(bytes_read > 0)
		{
			bytes_read = read(STDIN_FILENO, buffer, bufsize);
			if (bytes_read <= 0)
			{
					ft_bzero(buffer, bufsize);
					break;
			}
			str = ft_strjoinfree(str, buffer);
			//printf("%s\n", buffer);
			ft_bzero(buffer, bufsize);
		}
		printf("Has introducido: %s \n", str);
		return 0;
	}
}
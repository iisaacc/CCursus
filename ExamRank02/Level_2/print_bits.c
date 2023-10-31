#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	n;

	n = 0;
	i = 7;
	//Desplaza el bit en la pos i hasta la pos 0 y con la máscara & 1 lo aisla para poder imprimirlo de forma individual
	while (i >= 0)
	{
		n = '0' + ((octet >> i) & 1);
		write(1, &n, 1);
		i--;
	}
}

//int main()
//{
//	print_bits(255);
//}
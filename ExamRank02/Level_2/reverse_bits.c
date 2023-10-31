#include <unistd.h>
#include <stdio.h>

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

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	int				i2;
	unsigned char	n;

	n = 0;
	i = 7;
	i2 = 1;
	while (i >= 0)
	{
		n = n | ((octet >> i) & i2);
		printf("%d", i2);
		i2*= 2;
		i--;
	}
	return (n);
}

int main()
{
	print_bits(38);
	write(1,"\n", 1);
	print_bits(reverse_bits(38));
}
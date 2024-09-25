#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

	if (argc != 2)
	{
		std::cerr << "Usage: ./btc [file_name]" << std::endl;
		return 1;
	} else {
		try{
			BitcoinExchange exchange(argv[1]);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		return 0;
	}
}
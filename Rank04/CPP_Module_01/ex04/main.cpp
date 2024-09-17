#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

std::string ft_replace_str(std::string contents, std::string s1, std::string s2) {

	std::string new_cont;
	size_t		i;
	size_t		foundPos;

	i = 0;
	while (i < contents.length())
	{
		foundPos = contents.find(s1, i);
		if (foundPos != std::string::npos)
		{
			new_cont += contents.substr(i, foundPos - i);
			new_cont += s2;
			i = foundPos + s1.length();
			if (i == contents.length()){
				new_cont += contents.substr(i);
				return (new_cont);
			}
		}else
		{
			new_cont += contents.substr(i);
			return (new_cont);
		}
	}

	return (std::string());
}

int main(int argc, char *argv[])
{
	std::string	new_contents;
	std::string	contents;
	std::stringstream buffer;

	if (argc != 4)
		std::cout << "Introduce 3 arguments: [filename] [s1] [s2]" << std::endl;
	else
	{
		std::ifstream file(argv[1]);
		if (!file) {
			std::cerr << "Unable to open file \"" << argv[1] << "\"." << std::endl;
			return (1);
		}
		else {
			buffer << file.rdbuf();										//Leemos el contenido de file y lo insertamos en buffer
			contents = buffer.str();
			new_contents = ft_replace_str(contents, argv[2], argv[3]);	//Reemplaza las ocurrencias de s1 por s2 y devuelve un nuevo contenido modificado
			if (!new_contents.empty()) {
				std::string	filename = std::string(argv[1]) + ".replace";
				std::ofstream file(filename.c_str());					//Creamos un flujo de salida con ofstream y convertimos filename a const char * con .c_str()
				if (!file) {
					std::cerr << "Unable to create output file.";
					return (1);
				}
				else
					file << new_contents;
			}
		}
	}
	return (0);
}

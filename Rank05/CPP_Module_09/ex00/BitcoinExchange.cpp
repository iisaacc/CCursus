#include "BitcoinExchange.hpp"

float ft_StoFloat(std::string str) {
	float res;

	std::stringstream ss(str);
	ss >> res;
	if (ss.fail()) {
		throw std::runtime_error("Invalid float value: " + str);
	}
	return res;
}

void BitcoinExchange::printMap(std::map<BitcoinExchange::Date, float> map) {
	std::cout << "Printing map:" << std::endl;
	for (std::map<BitcoinExchange::Date, float>::iterator it = map.begin(); it != map.end(); it++) {
		std::cout << it->first.year << "-" << it->first.month << "-" << it->first.day << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
}

void	BitcoinExchange::parseCalculatePrices(BitcoinExchange::Date input_date, float value)
{
	std::map<Date, float>::iterator prev_it;

	if (value < 0)
		throw std::runtime_error("Error: not a positive numnber.");
	if (value > 1000)
		throw std::runtime_error("Error: too large a number.");
	std::map<Date, float>::iterator it = database.begin();
	prev_it = it;
	while (it != database.end() && input_date.year <= it->first.year) {
		prev_it = it;
		it++;
	}
	it = prev_it;
	while (it != database.end() && input_date.month <= it->first.month) {
		prev_it = it;
		it++;
	}
	it = prev_it;
	while (it != database.end() && input_date.day <= it->first.day) {
		prev_it = it;
		it++;
	}
	it = prev_it;
	std::cout << input_date.year << "-" << input_date.month << "-" << input_date.day << " => " << value << " = " << value * it->second << std::endl;
}

BitcoinExchange::Date BitcoinExchange::parseDate(std::string date) {
	Date date_struct;
	int pos = 0;
	int prev = 0;
	int year;
	int month;
	int day;

	pos = date.find("-");
	year = ft_StoFloat(date.substr(0, pos));
	if (year < 0 || year > std::numeric_limits<int>::max())
		throw std::runtime_error("Invalid year value: " + date);
	date_struct.year = year;
	prev = pos + 1;
	pos =  date.find("-", prev);
	month = ft_StoFloat(date.substr(prev, pos));
	if (month < 0 || month > 12)
		throw std::runtime_error("Invalid month value: " + date);
	date_struct.month = month;
	prev = pos + 1;
	pos =  date.find("-", prev);
	day = ft_StoFloat(date.substr(prev, pos));
	if (day < 0 || day > 31)
		throw std::runtime_error("Invalid day value: " + date);
	date_struct.day = day;
	return (date_struct);
}


std::map<BitcoinExchange::Date, float> BitcoinExchange::strToMap(std::string str, char delim)
{
	std::map<Date, float>	map;
	Date					date_struct;
	std::string::size_type	prev = 0;
	std::string::size_type	pos = str.find("\n", prev);
	prev = pos + 1;

	while ((pos = str.find("\n", prev)) != std::string::npos) {
		std::string line = str.substr(prev, pos - prev);
		try {
			if (line.find(delim) == std::string::npos) {
				throw std::runtime_error("Error: Bad input => " + line);
				continue;
			}
			std::string key = line.substr(0, line.find(delim));
			date_struct = parseDate(key);
			std::string value = line.substr(line.find(delim) + 1);
			map[date_struct] = ft_StoFloat(value);
			if (delim == '|')
				parseCalculatePrices(date_struct, ft_StoFloat(value));
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		prev = pos + 1;
	}
	return map;
}

BitcoinExchange::BitcoinExchange() {
	this->database = std::map<BitcoinExchange::Date, float>();
	this->input = std::map<BitcoinExchange::Date, float>();
}

std::string	BitcoinExchange::extractFileContent(std::string file_name) {
	std::stringstream	buffer;
	std::string			file_content;
	std::ifstream		file(file_name.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: Could not open file.");

	buffer << file.rdbuf();
	file_content = buffer.str();
	return file_content;
}

BitcoinExchange::BitcoinExchange(std::string file_name) {
	std::stringstream	buffer;
	std::string			database_content;
	std::string			input_content;

	database_content = extractFileContent("data.csv");
	this->database = strToMap(database_content, ',');
	printMap(database);
	input_content = extractFileContent(file_name);
	this->input = strToMap(input_content, '|');
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	this->database = other.database;
	this->input = other.input;
}

BitcoinExchange::~BitcoinExchange() {

}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &other) {
if (this != &other) {
		this->database = other.database;
		this->input = other.input;
	}
	return *this;
}
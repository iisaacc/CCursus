#pragma once

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <limits>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(std::string file_name);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		struct Date {
			int day;
			int month;
			int year;
			//Overcharge the operator < to compare the dates and sort them automatically in the map.
			bool operator<(const Date& other) const;
			bool operator>(const Date& other) const;
		};
	private:


		std::map<Date, float> database;
		std::map<Date, float> input;

		std::string extractFileContent(std::string file_name);
		std::map<Date, float> strToMap(std::string str, char delim);
		Date parseDate(std::string date);
		void parseCalculatePrices(Date date, float value);
		void printMap(std::map<Date, float> map);
		
};
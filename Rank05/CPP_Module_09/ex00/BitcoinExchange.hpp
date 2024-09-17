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

			bool operator<(const Date& other) const {
			if (year < other.year) return year < other.year;
			if (month < other.month) return month < other.month;
			return day < other.day;
			}
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
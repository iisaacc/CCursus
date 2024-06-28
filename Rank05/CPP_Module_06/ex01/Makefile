NAME = convert

CXX  = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = ScalarConverter.cpp main.cpp

HEADERS = ScalarConverter.hpp

all: $(NAME)

$(NAME): $(SOURCE) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)
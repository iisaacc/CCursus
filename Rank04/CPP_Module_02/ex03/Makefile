NAME = BSP

CXX  = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp Fixed.cpp Point.cpp bsp.cpp

HEADERS = Fixed.hpp Point.hpp

all: $(NAME)

$(NAME): $(SOURCE) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)
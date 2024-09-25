NAME = FragTrap

CXX  = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

HEADERS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

all: $(NAME)

$(NAME): $(SOURCE) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)
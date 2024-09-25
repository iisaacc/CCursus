NAME = Unnecessary_violence

CXX  = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp

all: $(NAME)

$(NAME): $(SOURCE) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)
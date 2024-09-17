NAME = ZombieHorde

CXX  = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = Zombie.cpp \
		main.cpp \
		zombieHorde.cpp

HEADERS = Zombie.hpp

all: $(NAME)

$(NAME): $(SOURCE) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)
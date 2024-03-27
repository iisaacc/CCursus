NAME = Zombie

CXX  = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = Zombie.cpp \
		randomChump.cpp \
		main.cpp

HEADERS = Zombie.hpp

all: $(NAME)

$(NAME): $(SOURCE) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)
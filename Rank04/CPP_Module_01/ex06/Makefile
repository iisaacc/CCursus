NAME = harlFilter

CXX  = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp Harl.cpp

HEADERS = Harl.hpp

all: $(NAME)

$(NAME): $(SOURCE) $(HEADERS)
	$(CXX) -Wno-implicit-fallthrough $(CXXFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)
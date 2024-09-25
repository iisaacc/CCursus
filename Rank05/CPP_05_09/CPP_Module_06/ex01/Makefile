NAME = Serialize

CXX  = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = Serialization.cpp main.cpp

HEADERS = Serialization.hpp

all: $(NAME)

$(NAME): $(SOURCE) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)
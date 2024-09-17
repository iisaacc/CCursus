NAME = SomeFunctions

CXX  = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = $(wildcard *.cpp)

HEADERS = $(wildcard *.hpp)

all: $(NAME)

$(NAME): $(SOURCE) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)
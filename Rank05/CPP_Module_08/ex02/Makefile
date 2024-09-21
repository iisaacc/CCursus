NAME = Mutated

CXX  = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = $(wildcard *.cpp)
OBJECTS = $(SOURCE:.cpp=.o)

HEADERS = $(wildcard *.hpp) $(wildcard *.tpp)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
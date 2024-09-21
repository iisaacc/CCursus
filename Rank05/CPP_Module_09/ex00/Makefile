NAME = btc

CXX  = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, obj/%.o, $(SOURCE))

HEADERS = $(wildcard *.hpp) $(wildcard *.tpp)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

obj/%.o: %.cpp $(HEADERS)
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf obj
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
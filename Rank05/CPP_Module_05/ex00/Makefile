NAME = Bureaucrat

CXX  = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp Bureaucrat.cpp

HEADERS = Bureaucrat.hpp

all: $(NAME)

$(NAME): $(SOURCE) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)
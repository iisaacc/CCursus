NAME = HI_THIS_BRAIN

CXX  = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = main.cpp

HEADERS = 

all: $(NAME)

$(NAME): $(SOURCE) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)
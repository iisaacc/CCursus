NAME = LostFile

CXX  = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = tests.cpp \
		Account.cpp

HEADERS = Account.hpp

all: $(NAME)

$(NAME): $(SOURCE) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)
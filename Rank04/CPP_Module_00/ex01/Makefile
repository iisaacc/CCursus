NAME = PhoneBook

CXX  = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = $(NAME).cpp \
		main.cpp \
		Contact.cpp

HEADERS = Contact.hpp \
		PhoneBook.hpp

all: $(NAME)

$(NAME): $(SOURCE) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)
NAME = Identify

CXX  = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCE = A.cpp B.cpp C.cpp Base.cpp main.cpp

HEADERS =  A.hpp B.hpp C.hpp Base.hpp

all: $(NAME)

$(NAME): $(SOURCE) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)
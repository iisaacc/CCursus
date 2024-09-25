NAME = Interface_recap

CXX  = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_PATH = ./Source

INCLUDE_PATH = ./Include

SOURCES = main.cpp MateriaSource.cpp Ice.cpp Cure.cpp Character.cpp AMateria.cpp

HEADERS = MateriaSource.hpp Ice.hpp Cure.hpp Character.hpp AMateria.hpp ICharacter.hpp IMateriaSource.hpp

SOURCES := $(addprefix $(SRC_PATH)/, $(SOURCES))

# Agrega el prefijo INCLUDE_PATH a cada archivo de cabecera
HEADERS := $(addprefix $(INCLUDE_PATH)/, $(HEADERS))

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_PATH) $(SOURCES) -o $(NAME)

clean:
	rm -f $(NAME)
# Implicit variables
CXX	    	=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic -g3 -fsanitize=address

# Headers and libraries
INC		 	=	-I.

# Executable name
EXEC		=	diamondtrap

# Source files
MAIN     	=	main.cpp
SRC		 	=	ClapTrap.cpp DiamondTrap.cpp FragTrap.cpp ScavTrap.cpp
OBJ      	=	$(SRC:.cpp=.o)

# Colour and format
BOLD		= 	\e[1m
PURPLE 		= 	\e[1;35m
GREEN		= 	\e[1;32m
PINK		= 	\e[38;2;255;124;212m
NEWLINE		= 	\e[1K\r
RESET		= 	\e[0m

all: $(EXEC)

$(EXEC): $(MAIN) $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) -o $(EXEC) $(MAIN) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) -rf *.dSYM

fclean: clean
	$(RM) $(EXEC)

re: fclean all

.PHONY: fclean
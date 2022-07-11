# Implicit variables
CXX		 =	c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98 -pedantic #-g3 -fsanitize=address

# Headers and libraries
INC		 = -I.

# Executable name
EXEC	 =	zombie

# Source files
MAIN     =  main.cpp
SRC		 =	Zombie.cpp zombieHorde.cpp
OBJ      =  $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(MAIN) $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) -o $(EXEC) $(MAIN) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(EXEC)

re: fclean all

.PHONY: fclean
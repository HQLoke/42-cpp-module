# Implicit variables
CXX		 =	c++
CXXFLAGS =	-Wall -Wextra -Werror -g -fsanitize=address -std=c++98 -pedantic

# Headers and libraries
INC		 = -I.

# Executable name
EXEC	 =	zombie

# Source files
MAIN     =  main.cpp
SRC		 =	newZombie.cpp randomChump.cpp Zombie.cpp 
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
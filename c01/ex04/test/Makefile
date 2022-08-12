# Implicit variables
CXX		 =	c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98 -pedantic -g3 -fsanitize=address

# Executable name
EXEC	 =	tester

# Source files
MAIN     =  main.cpp

all: $(EXEC)

$(EXEC): $(MAIN) $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) -o $(EXEC) $(MAIN)

clean:
	$(RM) *.replace *.test $(EXEC)
	$(RM) -rf *.dSYM

re: fclean all

.PHONY: fclean
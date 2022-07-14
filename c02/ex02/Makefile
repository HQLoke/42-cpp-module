# Implicit variables
CXX	    	=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic -g3 -fsanitize=address

# Headers and libraries
INC		 	=	-I.

# Executable name
EXEC		=	fixed

# Source files
MAIN     	=	main.cpp
SRC		 	=	Fixed.cpp
OBJ      	=	$(SRC:.cpp=.o)

# Test file
EXEC_TEST	=	test123
MAIN_TEST	=	test.cpp

all: $(EXEC)

$(EXEC): $(MAIN) $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) -o $(EXEC) $(MAIN) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

test: $(MAIN_TEST) $(OBJ)
	@$(CXX) $(CXXFLAGS) $(INC) -o $(EXEC_TEST) $(MAIN_TEST) $(OBJ)
	@./$(EXEC_TEST)
	@rm $(EXEC_TEST)

clean:
	$(RM) $(OBJ)
	$(RM) -rf *.dSYM

fclean: clean
	$(RM) $(EXEC)

re: fclean all

.PHONY: fclean
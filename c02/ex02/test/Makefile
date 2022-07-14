# Implicit variables
CXX	    	=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic -g3 -fsanitize=address

# Headers and libraries
INC		 	=	-I..

# Executable name
EXEC		=	test

# Source files
MAIN     	=	test.cpp
SRCDIR		=   ../
SRC			=	$(filter-out $(SRCDIR)/main.cpp, $(wildcard $(SRCDIR)/*.cpp))

# Colour and format
BOLD		= \e[1m
PURPLE		= \e[1;35m
GREEN		= \e[1;32m
PINK		= \e[38;2;255;124;212m
NEWLINE		= \e[1K\r
RESET		= \e[0m

all: $(EXEC)

$(EXEC): $(MAIN) $(SRC)
	@$(CXX) $(CXXFLAGS) $(INC) -o $(EXEC) $(MAIN) $(SRC)
	@printf "$(PINK)Testing in progress...\n\n$(RESET)"
	@./$(EXEC)
	@make fclean -silent
	@printf "$(PINK)\nTesting completed.\n$(RESET)"

clean:
	$(RM) $(OBJ)
	$(RM) -rf *.dSYM

fclean: clean
	$(RM) $(EXEC)

re: fclean all

.PHONY: fclean
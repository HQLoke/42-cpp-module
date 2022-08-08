# Implicit variables
CXX	    	=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic #-g3 -fsanitize=address

# Headers and libraries
INC		 	=	-Iinclude

# Executable name
EXEC		=	serialization

# Source files
MAIN     	=	main.cpp
SRCDIR		=   src
SRC		 	=	
OBJDIR		=   obj
OBJ      	=	$(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

# Colour and format
RESET		= 	\e[0m
BOLD		= 	\e[1m
RED			= 	\e[1;31m
GREEN		= 	\e[1;32m
PURPLE 		= 	\e[1;35m
PINK		= 	\e[38;2;255;124;212m
NEWLINE		= 	\e[1K\r


all: $(EXEC)

$(EXEC): $(MAIN) $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) -o $(EXEC) $(MAIN) $(OBJ)
	@printf "$(NEWLINE)$(GREEN)Successfully compiled $(EXEC)!\n$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@
	@printf "$(NEWLINE)Creating object file $@ from $<\n"

clean:
	@printf "$(NEWLINE)$(RED)Removing object files...\n$(RESET)"
	@$(RM) -rf $(OBJDIR)
	@$(RM) -rf *.dSYM

fclean: clean
	@printf "$(NEWLINE)$(RED)Removing $(EXEC)...\n$(RESET)"
	@$(RM) $(EXEC)

re: fclean all

.PHONY: fclean re
# Implicit variables
CXX		 =	c++
CXXFLAGS =	-Wall -Wextra -Werror -g -fsanitize=address -std=c++98 -pedantic

# Headers and libraries
INC		 = -I.

# Program name
NAME	 =	phonebook

# Source files
MAIN     =  main.cpp
SRC		 =	Contact.cpp PhoneBook.cpp
OBJ      =  $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(MAIN) $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) -o $(NAME) $(MAIN) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean
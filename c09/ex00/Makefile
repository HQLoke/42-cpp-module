NAME    	:=  btc

CXX     	:=  c++ 
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address

MAIN		:=	main.cpp
SRCS    	:=  BitcoinExchange.cpp
OBJS    	:=  $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(MAIN) $(OBJS)
	$(CXX) $(CXXFLAGS) $(MAIN) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
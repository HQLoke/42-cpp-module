NAME    :=  btc

CPP     :=  g++ -Wall -Wextra -Werror -std=c++98

MAIN	:=	main.cpp
SRCS    :=  BitcoinExchange.cpp
OBJS    :=  $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(MAIN) $(OBJS)
	@$(CPP) $(MAIN) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
NAME		= ircserv

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp \
			  Server/Server.cpp \
			  Client/Client.cpp \
			  Parser/Parser.cpp \

OBJS		= $(SRCS:.cpp=.o)

HEADERS		= includes/Server.hpp \
			  includes/Client.hpp \
			  includes/Parser.hpp \
			  includes/Command.hpp

INCLUDES	= -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
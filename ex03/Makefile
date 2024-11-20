CXX		:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -Wconversion -std=c++98
RM		:=	rm -f

TARGET	:=	a.out
SRCS    :=	main.cpp \
			AForm.cpp \
			Bureaucrat.cpp \
			Intern.cpp \
			PresidentialPardonForm.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp
OBJS    :=	$(patsubst %.cpp, %.o, $(SRCS))

.PHONY: all clean flean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

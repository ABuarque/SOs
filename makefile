CC = g++ 
CXXFLAGS=-g -Wall -I. -W -Wall 
LIBS = -lm 
DEPS = $(wildcard *.h)
SRC = $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

app: $(OBJ)
	g++ -o app $(SRC) -I. $(LIBS) 
	
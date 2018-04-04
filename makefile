CC = g++ 
CXXFLAGS=-g -Wall -std=c++11 -I. -W -Wall 
LIBS = -lm -std=c++11
DEPS = $(wildcard *.h)
SRC = $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

app: $(OBJ)
	g++ -o app $(SRC) -I. $(LIBS) 
	
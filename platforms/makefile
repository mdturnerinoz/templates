CC     := g++
CFLAGS := -Wall -g -O0
PROG   := example1

SRCS   := example1.cpp

all: $(PROG)

$(PROG): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) 

clean:
	rm -f $(PROG) *~

run: $(PROG)
	@./$(PROG) 


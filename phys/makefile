
CFLAGS= -g -ggdb -std=c++11 -Wall -Werror
OBJS=main.o
TARGET=./main

all: $(TARGET)

%.o : %.cpp matrix.h
	g++ -c $(CFLAGS) -o $@ $(*).cpp

$(TARGET): $(OBJS)
	g++ $(CFLAGS) -o $@ $(OBJS)

clean:
	/bin/rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	$(TARGET)

gdb: $(TARGET)
	gdb $(TARGET)

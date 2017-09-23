
CFLAGS= -g -std=c++11
OBJS=main.o
TARGET=./main

all: $(TARGET)

%.o : %.cpp
	g++ -c $(CFLAGS) -o $@ $^

$(TARGET): $(OBJS) matrix.h
	g++ $(CFLAGS) -o $@ $(OBJS)

clean:
	/bin/rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	$(TARGET)

gdb: $(TARGET)
	gdb $(TARGET)

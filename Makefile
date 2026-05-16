CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = build/telemetry-gateway

SRC = src/main.c src/uptime.c src/memory.c src/cpu.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
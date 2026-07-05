CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lmosquitto
TARGET = build/telemetry-gateway

SRC = src/main.c src/uptime.c src/memory.c src/cpu.c src/telemetry.c src/config.c src/json_formatter.c src/logger.c src/mqtt_publisher.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
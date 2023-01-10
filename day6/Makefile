CC		:=clang
CFLAGS	:=-O2 -g -Wall -Wextra
TARGET	:=build/output
SOURCES :=$(wildcard *.c)

all: build $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

build:
	@mkdir -p build

clean:
	rm -rf $(TARGET)
	rm -rf `find . -name "*dSYM" -print`
	rm -rf build
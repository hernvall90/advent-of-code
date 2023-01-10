CC		:=clang
CFLAGS	:=-g -O2 -Wall -Wextra
TARGET	:=build/output
SOURCES	:=$(wildcard *.c)

all: build $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

build:
	@mkdir -p build

clean:
	rm -rf $(TARGET)
	rm -rf `find . -name "*.dSYM" -print`
	rm -rf build
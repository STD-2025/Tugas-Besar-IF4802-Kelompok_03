CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++17 -I include

SOURCES = $(wildcard src/*.cpp)

ifeq ($(OS),Windows_NT)
    TARGET = bin/main.exe
    MKDIR = mkdir
    RM = del /q
    RUN = $(TARGET)
else
    TARGET = bin/main
    MKDIR = mkdir -p
    RM = rm -rf
    RUN = ./$(TARGET)
endif

all: run

build:
	@$(MKDIR) bin
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run:
	@if [ ! -f $(TARGET) ]; then \
		$(MAKE) build; \
	fi

	$(RUN)

clean:
	$(RM) bin/* build/*

.PHONY: all build run clean
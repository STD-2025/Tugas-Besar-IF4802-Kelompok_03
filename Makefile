CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++17 -I include

SOURCES = $(wildcard src/*.cpp)
TEST_SOURCES = $(wildcard test/*.cpp)

ifeq ($(OS),Windows_NT)
    TARGET = bin/main.exe
    TEST_TARGET = bin/test.exe
    MKDIR = mkdir
    RM = del /q
    RUN = $(TARGET)
else
    TARGET = bin/main
    TEST_TARGET = bin/test
    MKDIR = mkdir -p
    RM = rm -rf
    RUN = ./$(TARGET)
endif

all: run

# build target automatically
$(TARGET): $(SOURCES)
	@$(MKDIR) bin
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	$(RUN)

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_SOURCES)
	@$(MKDIR) bin
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) -o $(TEST_TARGET)
	@echo "Test build complete: $(TES
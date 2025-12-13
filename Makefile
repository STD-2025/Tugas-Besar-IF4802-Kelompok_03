CXX       := g++
CXXFLAGS  := -Wall -Wextra -O2 -std=c++17 -I include
LDFLAGS := -lncurses

SRCDIR    := src
OBJDIR    := obj
BINDIR    := bin
TARGET_NAME := main

ifeq ($(OS),Windows_NT)
  TARGET := $(BINDIR)/$(TARGET_NAME).exe
  MKDIR  := powershell -Command "New-Item -ItemType Directory -Force -Path"
  RM     := rmdir /s /q
  RUN    := $(TARGET)
else
  TARGET := $(BINDIR)/$(TARGET_NAME)
  MKDIR  := mkdir -p
  RM     := rm -rf
  RUN    := ./$(TARGET)
endif

SOURCES := $(shell find $(SRCDIR) -name '*.cpp')
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

all: obj bin run

obj: $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(MKDIR) $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(MKDIR) $(BINDIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

run: $(TARGET)
	@echo ""
	@echo "Running..."
	@echo ""
	@$(RUN)

clean:
	$(RM) $(OBJDIR) $(BINDIR)

.PHONY: all obj bin run clean
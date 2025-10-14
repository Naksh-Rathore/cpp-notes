# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 # -Iinclude <- Add for bigger projects with an include/ folder

# Detect platform
ifeq ($(OS),Windows_NT)
    SRCS := $(shell powershell -Command "Get-ChildItem -Recurse -Filter *.cpp | ForEach-Object { $$_.FullName }")
    RM := powershell -Command "Get-ChildItem -Include *.o -Recurse | Remove-Item -ErrorAction SilentlyContinue"
else
    SRCS := $(shell find . -name "*.cpp")
    RM := rm -f *.o
endif

OBJS := $(SRCS:.cpp=.o)
TARGET := main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)
	@echo Cleaning up object files...
	@$(RM)
	@echo Build successful!

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM)
	@rm -f $(TARGET) 2>nul || true

run: $(TARGET)
	./$(TARGET)

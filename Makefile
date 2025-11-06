
CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Iinclude
BUILD_DIR := build

all:
	@echo "Usage:"
	@echo "  make run PROB=0001_two_sum"
	@echo "  make clean"

NAME := $(notdir $(basename $(P)))
TARGET := $(BUILD_DIR)/$(NAME).out

$(BUILD_DIR)/%.out: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@


.PHONY: run
run: $(TARGET)
	@echo "=== Running $(P) ==="
	@./$(TARGET)

$(TARGET): $(P) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
BIN      := jogo
BUILD    := build

SRC := $(wildcard src/*.cpp)
OBJ := $(patsubst src/%.cpp,$(BUILD)/%.o,$(SRC))
DEP := $(OBJ:.o=.d)

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $@

$(BUILD)/%.o: src/%.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BUILD):
	@mkdir -p $(BUILD)

run: $(BIN)
	./$(BIN)

clean:
	rm -rf $(BUILD) $(BIN)

rebuild: clean all

.PHONY: all run clean rebuild

-include $(DEP)

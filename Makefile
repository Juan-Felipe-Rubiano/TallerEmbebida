CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = bin/taller
TEST_TARGET = bin/tests

SRC_DIR = src
TEST_DIR = test
BUILD_DIR = bin

SRC_SOURCES = $(wildcard $(SRC_DIR)/*.c)
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)

SRC_OBJECTS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SRC_SOURCES)))
TEST_OBJECTS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(TEST_SOURCES)))

SRC_OBJECTS_NO_MAIN = $(filter-out $(BUILD_DIR)/main.o,$(SRC_OBJECTS))

all: $(TARGET)

$(TARGET): $(SRC_OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(SRC_OBJECTS) -o $(TARGET) -lm

$(TEST_TARGET): $(SRC_OBJECTS_NO_MAIN) $(TEST_OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(SRC_OBJECTS_NO_MAIN) $(TEST_OBJECTS) -o $(TEST_TARGET) -lm

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

run: all
	./$(TARGET)

test: $(TEST_TARGET)
	@echo "Corriendo tests..."
	./$(TEST_TARGET)
	@echo "Todos los test aprobados"

.PHONY: docs cleandocs test run clean rebuild

docs:
	doxygen Doxyfile

cleandocs:
	rm -rf docs/html docs/latex

rebuild: clean all

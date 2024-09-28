# Tristan Sohr, Sep 2024

### basic names and locations ###
TARGET := sort
INCLUDE_DIR := include
SOURCE_DIR := source
BUILD_DIR := build
DEP_DIR := $(BUILD_DIR)/dep

### compiler and flags ###
CC := gcc
CFLAGS := -O3 -g -Wall -Wextra -I $(INCLUDE_DIR)#-pg
SPLINTFLAGS := -Wall -Werror -Wextra

### collecting files ###

# wildcard syntax to collect all .h files in INCLUDE_DIR
HEADERS := $(wildcard $(INCLUDE_DIR)/*.h)
# wildcard syntax to collect all .c files in SOURCE_DIR
SOURCES := $(wildcard $(SOURCE_DIR)/*.c)
# patsubst syntax to create .o file in BUILD_DIR for every .c file(given by SOURCES)
OBJECTS := $(patsubst $(SOURCE_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))
# patsubst syntax to create .d file in DEP_DIR for every .c file(given by SOURCES)
DEPENDENCIES := $(patsubst %.o, $(BUILD_DIR)/%.d, $(OBJECTS))
# allow makefile to use generated dependency files
-include $(DEPENDENCIES)

# declare which rules generate no files
.PHONY: run all clean lint

ifdef num # if an arg for num was given run this version
run: all
	./$(TARGET) "$(num)"
else # if num arg was missing, run this version
run: all
	./$(TARGET) 100
endif

all: $(TARGET)

# creates executable file, requires all object files to be generated
# compiles with compiler defined in CC with flags CFLAGS
# $^ lists all requirements as arguments and $@ to reference the rule name, TARGET
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ 

# creates build directory and dependencies directory if necessary
# creates all necessary .o files (and .d(directory) files)
# -MMD -MF$(DEP_DIR)/$*.d creates and places all .d files into the DEP_DIR
# $< references the first requirment

$(BUILD_DIR)/%.o : $(SOURCE_DIR)/%.c $(INCLUDE_DIR)/%.h
	mkdir -p $(BUILD_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS) -MMD -MF $(DEP_DIR)/$*.d -c $< -o $@

# removes all created files, specifically all those placed in BUILD_DIR as well as TARGET
clean:
	rm -rf $(BUILD_DIR)/* $(TARGET)

# lints the headers and source files. Appends with or to prevent makefile errors
lint:
	splint $(SPLINTFLAGS) -I$(INCLUDE_DIR) -I$(SOURCE_DIR) $(HEADERS) $(SOURCES) || true

docs:
	cd docs; doxygen Doxygile; cd ..
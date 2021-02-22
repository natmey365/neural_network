#======================================================
# Files and directories
#======================================================
LIB          := lib_neural_network.a
SRC_DIR      := src
INC_DIR      := inc
TEST_DIR     := test
OBJ_DIR      := obj

SRC_FILES    := $(wildcard $(SRC_DIR)/*.cpp)
INC_FILES    := $(wildcard $(INC_DIR)/*.h)
OBJS         := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

#======================================================
# Compiler, Archiver, and flags
#======================================================
CPP            := g++
COMPILE_FLAGS  := -Wall -I$(INC_DIR)
AR             := ar rcs

#======================================================
# Targets
#======================================================
.PHONY: clean test

all: clean test

#=========
# Library
#=========
lib: $(LIB)
neural_network: $(LIB)

$(LIB): lib_deps lib_objs
	@echo "============================================="; \
	 echo "= Building $(LIB)             ="; \
	 echo "============================================="
	$(AR) $@ $(OBJS)

lib_deps:

$(OBJ_DIR)/%.o: src/%.cpp inc/%.h | $(OBJ_DIR)
	$(CPP) $(COMPILE_FLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

lib_objs:
	@echo "============================================="; \
	 echo "= Compiling $(LIB) objects    ="; \
	 echo "============================================="
	$(MAKE) $(OBJS)

#=========
# Test
#=========
test: $(LIB)
	@echo "============================================="; \
	 echo "= Running Tests                             ="; \
	 echo "============================================="
	$(MAKE) -C $(TEST_DIR)

#=========
# Clean
#=========
clean:
	rm -rf $(LIB) $(OBJ_DIR)
	$(MAKE) -C $(TEST_DIR) clean

#======================================================
# Testing
#======================================================


#======================================================
# Files and directories
#======================================================
LIB               := neural_network
SRC_DIR           := src
INC_DIR           := inc
TEST_DIR          := test
BIN_DIR           := bin

SRC_FILES     := $(wildcard $(SRC_DIR)/*.cpp)
INC_FILES     := $(wildcard $(INC_DIR)/*.h)
BINS          := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%,$(SRC_FILES))

#======================================================
# Compiler and flags
#======================================================
CPP            := g++
COMPILE_FLAGS  := -Wall -I$(INC_DIR) -I../inc -L../ -l_$(LIB)

#======================================================
# Targets
#======================================================
.PHONY: test

all: test

#=========
# Run
#=========
test: $(BINS)
	@for test in $(BINS); do \
		./$$test $(OPTS); \
	done

#=========
# Build
#=========
$(BIN_DIR)/%: src/%.cpp inc/%.h | $(BIN_DIR)
	$(CPP) $(COMPILE_FLAGS) -o $@ $<

$(BIN_DIR):
	mkdir -p $@

#=========
# Clean
#=========
clean:
	rm -rf bin

#======================================================
# Testing
#======================================================
bins:
	@echo $(BINS)

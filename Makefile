#======================================================
# Files and directories
#======================================================
LIB_NAME      := neural_network
LIB           := lib_neural_network.a
SRC_DIR       := src
INC_DIR       := inc
OBJ_DIR       := obj
TST_DIR       := test
TST_SRC_DIR   := $(TST_DIR)/src
TST_INC_DIR   := $(TST_DIR)/inc
TST_BIN_DIR   := $(TST_DIR)/bin

SRC_FILES     := $(wildcard $(SRC_DIR)/*.cpp)
INC_FILES     := $(wildcard $(INC_DIR)/*.h)
OBJS          := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
TST_SRC_FILES := $(wildcard $(TST_SRC_DIR)/*.cpp)
TST_INC_FILES := $(wildcard $(TST_INC_DIR)/*.h)
TST_BINS      := $(patsubst $(TST_SRC_DIR)/%.cpp,$(TST_BIN_DIR)/%,$(TST_SRC_FILES))

#======================================================
# Compiler, Archiver, and flags
#======================================================
CPP               := g++
COMPILE_FLAGS     := -Wall -I$(INC_DIR)
TST_COMPILE_FLAGS := -Wall -I$(INC_DIR) -I$(TST_INC_DIR) -L. -l_$(LIB_NAME)
AR                := ar rcs

#======================================================
# Targets
#======================================================
.PHONY: clean test

all: $(LIB)

#=========
# Library
#=========
lib: $(LIB)
neural_network: $(LIB)

$(LIB): lib_objs $(SRC_FILES) $(INC_FILES)
	@echo "============================================="; \
	 echo "= Building $(LIB)             ="; \
	 echo "============================================="
	$(AR) $@ $(OBJS)

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
test: lib test_bins
	@echo "============================================="; \
	 echo "= Compiling $(LIB) objects    ="; \
	 echo "============================================="
	@for test in $(TST_BINS); do \
                ./$$test $(OPTS); RC=$$?; \
		if [ $$RC -eq 0 ]; then \
			echo "$$test Passed!"; \
		else \
			echo "$$test Failed!"; \
		fi; \
	done

test_bins:
	@echo "============================================="; \
	 echo "= Building Tests                            ="; \
	 echo "============================================="
	$(MAKE) $(TST_BINS)
		
$(TST_BIN_DIR)/%: $(TST_SRC_DIR)/%.cpp $(TST_INC_DIR)/%.h | $(TST_BIN_DIR)
	$(CPP) $(TST_COMPILE_FLAGS) -o $@ $<

$(TST_BIN_DIR):
	mkdir -p $@

#=========
# Clean
#=========
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(LIB)
	rm -rf $(TST_BIN_DIR)

#======================================================
# Files and directories
#======================================================
EXECUTABLE := main
SRC_DIR    := src
INC_DIR    := inc
OBJ_DIR    := obj
SRC_FILES  := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES  := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

#======================================================
# Compiler and flags
#======================================================
CXX        :=
CPP        := g++
LDFLAGS    :=
CPPFLAGS   :=
CXXFLAGS   :=

#======================================================
# Targets
#======================================================
.PHONY: clean

$(EXECUTABLE): $(OBJ_FILES)
	$(CPP) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h | $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) -I$(INC_DIR) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)/* $(EXECUTABLE)

SRC_DIR   := ./src
INC_DIR   := ./inc
OBJ_DIR   := ./obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS   :=
CPPFLAGS  :=
CXXFLAGS  :=

.PHONY: clean

main: $(OBJ_FILES)
	g++ $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp #$(INC_DIR)/%.h
	@mkdir -p obj
	g++ $(CPPFLAGS) $(CXXFLAGS) -I$(INC_DIR) -c -o $@ $<

clean:
	rm -rf ./obj/ ./main

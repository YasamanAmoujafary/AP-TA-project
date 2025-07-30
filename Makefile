GPP = g++
GPPFLAGS = -std=c++2a -I./header
SRC_DIR = src
OBJ_DIR = obj
EXES = ./ChiBebinam

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
 
clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(EXES)

all : $(EXES)

$(EXES) : $(OBJECTS)
	$(GPP) $(GPPFLAGS) -o $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(wildcard $(SRC_DIR)/*.hpp)
	mkdir -p $(OBJ_DIR)
	$(GPP) $(GPPFLAGS) -c $< -o $@
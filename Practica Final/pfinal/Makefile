CC = g++
CPPFLAGS = -Wall -g -I$(INCLUDE) -std=c++11
SRC = ./src
INCLUDE = ./inc
OBJ = ./obj
BIN = ./bin
DOC = ./doc
SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)


docum:
	doxygen doc/doxys/Doxyfile

build:$(BIN)/testdiccionario $(BIN)/letras $(BIN)/testbolsaletras

$(BIN)/letras:$(OBJ)/letras.o $(OBJ)/diccionario.o $(OBJ)/ConjuntoLetras.o $(OBJ)/BolsaLetras.o $(OBJ)/Letra.o
	$(CC) $(CPPFLAGS) -o $@ $^

$(BIN)/testdiccionario:$(OBJ)/testdiccionario.o $(OBJ)/diccionario.o $(OBJ)/ConjuntoLetras.o $(OBJ)/BolsaLetras.o $(OBJ)/Letra.o
	$(CC) $(CPPFLAGS) -o $@ $^

$(BIN)/testbolsaletras:$(OBJ)/testbolsaletras.o $(OBJ)/ConjuntoLetras.o $(OBJ)/BolsaLetras.o $(OBJ)/Letra.o
	$(CC) $(CPPFLAGS) -o $@ $^

$(OBJECTS): $(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $<

clean :
	-rm $(OBJ)/*.o $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*

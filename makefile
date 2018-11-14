COMPILER = clang++
FLAGS = -std=c++11
BIN = bin/static-site-generator
BINCHECK = if [ ! -d bin ]; then mkdir bin; fi;

$(BIN) : main.cpp fileText.h page.h
	$(BINCHECK) $(COMPILER) $(FLAGS) main.cpp -o $(BIN)

# tests
#======

# execute binary
check :
	$(BIN)

# test manifest file and includes
manifest:
	cd tests/manifest-test; ../../$(BIN)

#==========
# end tests

clean :
	rm -rf bin
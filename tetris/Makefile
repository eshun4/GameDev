CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

tetris: tetris.cpp
	$(CXX) $(CXXFLAGS) tetris.cpp -o tetris $(LIBS)

run: tetris
	./tetris

clean:
	rm -f tetris

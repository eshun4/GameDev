CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

axe_game: axe_game.cpp
	$(CXX) $(CXXFLAGS) axe_game.cpp -o axe_game $(LIBS)

run: axe_game
	./axe_game

clean:
	rm -f axe_game

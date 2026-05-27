CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

pong: pong.cpp
	$(CXX) $(CXXFLAGS) pong.cpp -o pong $(LIBS)

run: pong
	./pong

clean:
	rm -f pong

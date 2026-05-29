CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

dapper_dasher: dapper_dasher.cpp
	$(CXX) $(CXXFLAGS) dapper_dasher.cpp -o dapper_dasher $(LIBS)

run: dapper_dasher
	./dapper_dasher

clean:
	rm -f dapper_dasher

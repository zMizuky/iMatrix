CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
LDFLAGS = -lSDL3

TARGET = game # Aqui é o nome do executável
SRC = main.cpp # Aqui é o seu .cpp. Se criou uma pasta coloque também (/src/main.cpp, por exemplo)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(TARGET) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

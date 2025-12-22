SYSCONF_LINK = g++
CPPFLAGS     = -Wall -Wextra -Weffc++ -pedantic -std=c++11 -O3
LDFLAGS      = 
LIBS         = -lSDL2 -lm -lSDL2_ttf -lSDL2_mixer

DESTDIR = ./
TARGET  = main

OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: $(DESTDIR)$(TARGET)

$(DESTDIR)$(TARGET): $(OBJECTS)
	$(SYSCONF_LINK) -Wall $(LDFLAGS) -o $(DESTDIR)$(TARGET) $(OBJECTS) $(LIBS)

$(OBJECTS): %.o: %.cpp
	$(SYSCONF_LINK) -Wall $(CPPFLAGS) -c $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f $(TARGET)

CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -O3
TARGET = main.exe
OBJS = button.o leaderboard.o main.o map.o menu.o player.o renderer.o sound.o timer.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer -lm

button.o: button.cpp button.h
	$(CXX) $(CXXFLAGS) -c button.cpp -o button.o

leaderboard.o: leaderboard.cpp leaderboard.h
	$(CXX) $(CXXFLAGS) -c leaderboard.cpp -o leaderboard.o

main.o: main.cpp game.h renderer.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

map.o: map.cpp map.h
	$(CXX) $(CXXFLAGS) -c map.cpp -o map.o

menu.o: menu.cpp menu.h
	$(CXX) $(CXXFLAGS) -c menu.cpp -o menu.o

player.o: player.cpp player.h
	$(CXX) $(CXXFLAGS) -c player.cpp -o player.o

renderer.o: renderer.cpp renderer.h
	$(CXX) $(CXXFLAGS) -c renderer.cpp -o renderer.o

sound.o: sound.cpp sound.h
	$(CXX) $(CXXFLAGS) -c sound.cpp -o sound.o

timer.o: timer.cpp timer.h
	$(CXX) $(CXXFLAGS) -c timer.cpp -o timer.o

clean:
	rm -f $(OBJS) $(TARGET)

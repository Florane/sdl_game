RUN=g++
CFLAGS=-g -c
LIBRARIES=-lSDL2 -lSDL2_ttf
SOURCES=rect.cpp menu.cpp tilemap.cpp player.cpp level.cpp draw.cpp complex_menu.cpp complex_tilemap.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXEC=run

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJECTS)
	$(RUN) $(LIBRARIES) $(OBJECTS) -o $(EXEC)

.cpp.o:
	$(RUN) $(CFLAGS) $<

clean:
	rm -rf *.o $(EXEC)

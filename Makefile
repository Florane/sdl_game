RUN=g++
CFLAGS=-g -c
LIBRARIES=-lSDL2 -lSDL2_ttf
SOURCES=rect.cpp menu.cpp tilemap.cpp platform.cpp player.cpp level.cpp draw.cpp complex_menu.cpp complex_tilemap.cpp platformFactory.cpp complex_platforms.cpp collision.cpp complex_collision.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXEC=run

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJECTS)
	$(RUN) $(LIBRARIES) $(OBJECTS) -o $(EXEC)

.cpp.o:
	$(RUN) $(CFLAGS) $<

clean:
	rm -rf *.o $(EXEC)

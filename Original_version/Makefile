CC = gcc

CFLAGS = -O2 -I./src -I/usr/include/SDL2 -DHOMEDIR
LDFLAGS = -lSDL2 -lm -lSDL2_mixer

DEFINES = -Wall
OUTPUT = killminds.elf

SOURCES = src/main.c src/sdl2/wrapper.c
OBJS = ${SOURCES:.c=.o}

${OUTPUT}:${OBJS}
	${CC} -o ${OUTPUT} ${OBJS} ${CFLAGS} ${LDFLAGS} ${DEFINES} 
	
clean:
	rm *.o
	rm ${OUTPUT}

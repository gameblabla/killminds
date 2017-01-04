CC = gcc

CFLAGS = -O2 -I/usr/include/SDL2 -DSELFISHOS -DHOMEDIR
#-DENABLE_OPENAL -Igorilla-audio/include
LDFLAGS = -lSDL2 -lm -s -flto
DEFINES = -Wall
OUTPUT = harbour-killminds

SOURCES = main.c wrapper_sail.c
#./gorilla-audio/src/ga.c \
#./gorilla-audio/src/gau.c \
#./gorilla-audio/src/ga_stream.c \
#./gorilla-audio/src/devices/ga_openal.c \
#./gorilla-audio/src/common/gc_common.c \
#./gorilla-audio/src/common/gc_thread.c
OBJS = ${SOURCES:.c = .o}

${OUTPUT}:${OBJS}
	${CC} -o ${OBJS} ${CFLAGS} ${LDFLAGS} ${DEFINES} 
	
clean:
	rm *.o ${OUTPUT}

install:
	chmod +x ${OUTPUT}
	mkdir /home/deploy/installroot
	mkdir /home/deploy/installroot/usr
	mkdir /home/deploy/installroot/usr/bin
	mkdir /home/deploy/installroot/usr/share
	mkdir /home/deploy/installroot/usr/share/harbour-killminds
	mkdir /home/deploy/installroot/usr/share/applications
	mkdir /home/deploy/installroot/usr/share/icons
	mkdir /home/deploy/installroot/usr/share/icons/hicolor
	mkdir /home/deploy/installroot/usr/share/icons/hicolor/86x86
	mkdir /home/deploy/installroot/usr/share/icons/hicolor/86x86/apps
	cp ./$(OUTPUT) /home/deploy/installroot/usr/bin/$(OUTPUT)
	cp ./killminds.desktop /home/deploy/installroot/usr/share/applications/harbour-killminds.desktop
	cp ./data/86x86.png /home/deploy/installroot/usr/share/icons/hicolor/86x86/apps/harbour-killminds.png
	cp ./data/all.bmp /home/deploy/installroot/usr/share/harbour-killminds/all.bmp
	cp ./data/back.bmp /home/deploy/installroot/usr/share/harbour-killminds/back.bmp
	cp ./data/background.bmp /home/deploy/installroot/usr/share/harbour-killminds/background.bmp
	cp ./data/block.bmp /home/deploy/installroot/usr/share/harbour-killminds/block.bmp
	cp ./data/smallblock.bmp /home/deploy/installroot/usr/share/harbour-killminds/smallblock.bmp
	cp ./data/copyright.bmp /home/deploy/installroot/usr/share/harbour-killminds/copyright.bmp
	cp ./data/hand_anim.bmp /home/deploy/installroot/usr/share/harbour-killminds/hand_anim.bmp
	cp ./data/heart.bmp /home/deploy/installroot/usr/share/harbour-killminds/heart.bmp
	cp ./data/inst.bmp /home/deploy/installroot/usr/share/harbour-killminds/inst.bmp
	cp ./data/score.bmp /home/deploy/installroot/usr/share/harbour-killminds/score.bmp
	cp ./data/startbutton.bmp /home/deploy/installroot/usr/share/harbour-killminds/startbutton.bmp
	cp ./data/title.bmp /home/deploy/installroot/usr/share/harbour-killminds/title.bmp
	cp ./data/trophees.bmp /home/deploy/installroot/usr/share/harbour-killminds/trophees.bmp
	cp ./data/downleft.wav /home/deploy/installroot/usr/share/harbour-killminds/downleft.wav
	cp ./data/downright.wav /home/deploy/installroot/usr/share/harbour-killminds/downright.wav
	cp ./data/fullsquare.wav /home/deploy/installroot/usr/share/harbour-killminds/fullsquare.wav
	cp ./data/gameover.wav /home/deploy/installroot/usr/share/harbour-killminds/gameover.wav
	cp ./data/miss.wav /home/deploy/installroot/usr/share/harbour-killminds/miss.wav
	cp ./data/move1.wav /home/deploy/installroot/usr/share/harbour-killminds/move1.wav
	cp ./data/move2.wav /home/deploy/installroot/usr/share/harbour-killminds/move2.wav
	cp ./data/move3.wav /home/deploy/installroot/usr/share/harbour-killminds/move3.wav
	cp ./data/move4.wav /home/deploy/installroot/usr/share/harbour-killminds/move4.wav
	cp ./data/upleft.wav /home/deploy/installroot/usr/share/harbour-killminds/upleft.wav
	cp ./data/upright.wav /home/deploy/installroot/usr/share/harbour-killminds/upright.wav

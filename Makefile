

game:main.o perso.o
	gcc main.o perso.o -o game  -lSDL -lSDL_image -lSDL_mixer -g 

main.o:main.c
	gcc main.c -c  -lSDL -lSDL_image -lSDL_mixer -g


perso.o:perso.c
	gcc perso.c -c -lSDL -lSDL_image -lSDL_mixer -g

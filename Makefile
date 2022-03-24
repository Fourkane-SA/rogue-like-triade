all: bin/app

LIBS =  -lsfml-graphics -lsfml-window -lsfml-system
ISFML = -ISFML

_OBJ = main.o Collision.o Etage.o Salle.o jeu.o Obstacle.o Personnage.o Monstre.o Objet.o Projectile.o BarreDeVie.o
OBJ = $(patsubst %,obj/%,$(_OBJ))

obj/%.o: src/%.cpp
	g++ -Wall -c -o $@ $< $(ISFML)

bin/app: $(OBJ)
	g++ -Wall -o bin/app $^ $(LIBS)

clean:
	rm -f obj/* bin/*

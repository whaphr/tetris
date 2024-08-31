tetris:
	g++ src/*.cpp -o tetris -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf tetris

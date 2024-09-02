TETRIS_SRC := src/piece.cpp

tetris: src/main.cpp ${TETRIS_SRC}
	g++ src/main.cpp ${TETRIS_SRC} -o tetris -lsfml-graphics -lsfml-window -lsfml-system

test_piece: src/test_piece.cpp ${TETRIS_SRC}
	g++ src/test_piece.cpp ${TETRIS_SRC} -o test_piece -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf tetris
	rm -rf test_piece

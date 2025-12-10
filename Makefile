CC = g++
CFLAGS = -std=c++20 -Wall # flags de compilação: C++20 e alertas ativados
TARGET = main           # nome executável
SOURCES = main.cpp Personagem.cpp Banco.cpp # todos os arquivos .cpp

$(TARGET): $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $(TARGET)

# remover arquivos compilados
clean:
	rm -f $(TARGET) *.o
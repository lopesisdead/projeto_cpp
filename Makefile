CC = g++
# -Iinclude diz ao gcc para procurar os arquivos.h na pasta include
CFLAGS = -std=c++20 -Wall -Iinclude 
# -lpqxx -lpq vincula a biblioteca do PostgreSQL
LIBS = -lpqxx -lpq
TARGET = main

# localiza todos os arquivos .cpp na pasta src
SOURCES = $(wildcard src/*.cpp)

$(TARGET): $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(LIBS) -o $(TARGET)

clean:
	rm -f $(TARGET)
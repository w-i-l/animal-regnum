CC = g++

all: main.exe

main.exe: animal.o bird.o reptile.o mammal.o archaeopteryx.o menu.o main.o
	@echo "Linking..."
	@$(CC) animal.o bird.o reptile.o mammal.o archaeopteryx.o menu.o main.o -o main.exe

animal.o: Files/Classes/animal.cpp
	echo "Compiling animal.cpp..."
	@$(CC) -c Files/Classes/animal.cpp -o animal.o

bird.o: Files/Classes/bird.cpp
	@echo "Compiling bird.cpp..."
	@$(CC) -c Files/Classes/bird.cpp -o bird.o

reptile.o: Files/Classes/reptile.cpp
	@echo "Compiling reptile.cpp..."
	@$(CC) -c Files/Classes/reptile.cpp -o reptile.o

mammal.o: Files/Classes/mammal.cpp
	@echo "Compiling mammal.cpp..."
	@$(CC) -c Files/Classes/mammal.cpp -o mammal.o

archaeopteryx.o: Files/Classes/archaeopteryx.cpp
	@echo "Compiling archaeopteryx.cpp..."
	@$(CC) -c Files/Classes/archaeopteryx.cpp -o archaeopteryx.o

menu.o: Files/Menu/menu.cpp
	@echo "Compiling menu.cpp..."
	@$(CC) -c Files/Menu/menu.cpp -o menu.o

main.o: main.cpp
	@echo "Compiling main.cpp..."
	@$(CC) -c main.cpp -o main.o

clean:
	@echo "Cleaning all .o files..."
	@del *.o
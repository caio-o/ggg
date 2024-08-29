ifeq ($(OS),Windows_NT) 
    RM = del /Q /F
    CP = copy /Y
	ifdef ComSpec
		SHELL := $(ComSpec)
	endif
	ifdef COMSPEC
		SHELL := $(COMSPEC)
	endif
else
	RM = rm 
	CP = cp -f
endif

call:
	clean all

clean:
	$(RM) *.o main.exe

all: compile link

compile:
	g++.exe -I"C:/SFML-2.6.1/include/" -I"../src/" -c ../src/*.cpp ../src/Testes/*.cpp ../src/Gerenciadores/*.cpp ../src/Entidades/*.cpp ../src/Entidades/Personagens/*.cpp ../src/ElementosGraficos/*.cpp ../src/Entidades/Personagens/Inimigos/*.cpp ../src/Fases/*.cpp ../src/Listas/*.cpp ../src/Entidades/Obstaculos/*.cpp ../src/Menus/*.cpp

link:
	g++.exe *.o -o main -L"C:/SFML-2.6.1/lib/" -lsfml-graphics -lsfml-window -lsfml-system
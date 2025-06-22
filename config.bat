@echo off
chcp 65001 > nul
cd src
g++ Main.cpp Morador.cpp Os.cpp Persistencia.cpp Pessoa.cpp Tecnico.cpp -I../include -o Main.exe
echo Compilado com sucesso!
echo.
.\Main.exe
pause

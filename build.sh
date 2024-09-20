mkdir -p lib
gcc -c GCFK.c -o ./lib/GCFK.o
ar rcs ./lib/libGCFK.a ./lib/GCFK.o
gcc -c oled.c -o ./lib/oled.o
ar rcs ./lib/liboled.a ./lib/oled.o

g++ main.cpp -lwiringPi -I ./ -L ./lib -lGCFK -loled -o main
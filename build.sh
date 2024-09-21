mkdir -p lib
echo "Buiding Libraries..."
gcc -c GCFK.c -o ./lib/GCFK.o
ar rcs ./lib/libGCFK.a ./lib/GCFK.o
gcc -c oled.c -o ./lib/oled.o
ar rcs ./lib/liboled.a ./lib/oled.o

echo "Building main..."
g++ main.cpp -lwiringPi -I ./ -L ./lib -lGCFK -loled -o main
echo "Buiding test..."
g++ test.cpp Polonium/Page.cpp Polonium/Element.cpp Polonium/Elements/TextElements.cpp -o test -loled -lGCFK -lwiringPi -L ./lib
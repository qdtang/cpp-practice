test1:
	rm -rf libalgo.so
	ln -s libalgo1.so libalgo.so
	./main

test2:
	rm -rf libalgo.so
	ln -s libalgo2.so libalgo.so
	./main

compile: libalgo1.so libalgo2.so main

main: main.cpp
	g++ main.cpp -ldl -o main

libalgo1.so: algo1.cpp
	g++ algo1.cpp -shared -fPIC -o libalgo1.so

libalgo2.so: algo2.cpp
	g++ algo2.cpp -shared -fPIC -o libalgo2.so

clean:
	rm -rf *.so main

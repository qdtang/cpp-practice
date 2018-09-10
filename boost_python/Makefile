all: hello.so test

hello.so: hello.cpp
	$(CXX) -fPIC -shared $^ -o $@ -I/usr/include/python2.7/ -lboost_python

test: hello.so
	@python test.py

clean:
	rm -rf hello.so

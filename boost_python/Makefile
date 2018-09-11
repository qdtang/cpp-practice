.PHONY: all cpp python
all: cpp python

cpp: test
	./$<

python: test.py hello.so
	python2.7 $<

test: test.cpp hello.o
	$(CXX) $^ -o $@

hello.o: hello.cpp
	$(CXX) -c -fPIC $< -o $@

hello.so: hello.o hello_py.cpp
	$(CXX) -shared -fPIC $^ -o $@ -I/usr/include/python2.7/ -lboost_python

hello.cpp hello_py.cpp test.cpp: hello.h
	touch $@

clean:
	$(RM) hello.o hello.so test

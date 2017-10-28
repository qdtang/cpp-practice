override CXXFLAGS += -Wall -Werror -std=c++11
.PHONY: clean debug release

TARGET = main
CWD = $(shell pwd)

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g

debug release: $(TARGET)

$(TARGET): main.cpp libhello.so
	$(CXX) $(CXXFLAGS) $< -L$(PWD) -lhello -Wl,-rpath=$(PWD) -o $@
	@echo ======================OUTPUT======================
	@./$(TARGET)

main.cpp hello.cpp: hello.h
	touch $@

hello.o: hello.cpp
	$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@

libhello.so: hello.o
	$(CXX) $(CXXFLAGS) -shared $< -o $@

clean:
	$(RM) $(TARGET) *.so *.o

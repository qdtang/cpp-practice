override CXXFLAGS += -Wall -Werror -std=c++11
.PHONY: clean debug release

TARGET = main

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g

debug release: $(TARGET)

$(TARGET): main.cpp libhello.a
	$(CXX) $(CXXFLAGS) $< -L. -lhello -o $@
	@echo ======================OUTPUT======================
	@./$(TARGET)

main.cpp hello.cpp: hello.h
	touch $@

hello.o: hello.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

libhello.a: hello.o
	ar rcs $@ $^

clean:
	$(RM) $(TARGET) *.a *.o

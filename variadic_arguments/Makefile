override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< variadic_arguments
@echo ======================OUTPUT======================
@./variadic_arguments
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: variadic_arguments-g
	$(run)
	
release: variadic_arguments-o
	$(run)


variadic_arguments-g variadic_arguments-o: variadic_arguments.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) variadic_arguments variadic_arguments-*

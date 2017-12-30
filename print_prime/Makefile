override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< print_prime
@echo ======================OUTPUT======================
@./print_prime
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: print_prime-g
	$(run)
	
release: print_prime-o
	$(run)


print_prime-g print_prime-o: print_prime.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) print_prime print_prime-*

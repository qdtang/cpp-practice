override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean

print_prime: print_prime.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) print_prime

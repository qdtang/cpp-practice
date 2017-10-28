override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

release: CXXFLAGS += -O2
debug: CXXFLAGS += -g

debug release: optional

optional: optional.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo ======================OUTPUT======================
	@./$@

clean:
	$(RM) optional 

override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
@ln -s -f $< chrono
@echo ======================OUTPUT======================
@./chrono
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: chrono-g
	$(run)

release: chrono-o
	$(run)


chrono-g chrono-o: chrono.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) chrono chrono-*

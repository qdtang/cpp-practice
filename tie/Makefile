override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< tie
@echo ======================OUTPUT======================
@./tie
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: tie-g
	$(run)
	
release: tie-o
	$(run)


tie-g tie-o: tie.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) tie tie-*

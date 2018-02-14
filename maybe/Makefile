override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< maybe
@echo ======================OUTPUT======================
@./maybe
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: maybe-g
	$(run)
	
release: maybe-o
	$(run)


maybe-g maybe-o: maybe.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) maybe maybe-*

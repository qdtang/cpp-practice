override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
@ln -s -f $< forwardlist
@echo ======================OUTPUT======================
@./forwardlist
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: forwardlist-g
	$(run)

release: forwardlist-o
	$(run)


forwardlist-g forwardlist-o: forwardlist.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) forwardlist forwardlist-*

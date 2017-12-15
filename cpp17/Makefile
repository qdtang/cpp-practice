override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
@ln -s -f $< cpp17
@echo ======================OUTPUT======================
@./cpp17
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: cpp17-g
	$(run)

release: cpp17-o
	$(run)


cpp17-g cpp17-o: cpp17.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) cpp17 cpp17-*

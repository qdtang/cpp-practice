override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
@ln -s -f $< boolvector
@echo ======================OUTPUT======================
@./boolvector
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: boolvector-g
	$(run)

release: boolvector-o
	$(run)


boolvector-g boolvector-o: boolvector.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) boolvector boolvector-*

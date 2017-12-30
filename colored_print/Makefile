override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< colored_print
@echo ======================OUTPUT======================
@./colored_print
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: colored_print-g
	$(run)
	
release: colored_print-o
	$(run)


colored_print-g colored_print-o: colored_print.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) colored_print colored_print-*

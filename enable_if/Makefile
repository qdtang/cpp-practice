override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< enable_if
@echo ======================OUTPUT======================
@./enable_if
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: enable_if-g
	$(run)
	
release: enable_if-o
	$(run)


enable_if-g enable_if-o: enable_if.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) enable_if enable_if-*

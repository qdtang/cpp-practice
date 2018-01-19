override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< bind_override
@echo ======================OUTPUT======================
@./bind_override
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: bind_override-g
	$(run)
	
release: bind_override-o
	$(run)


bind_override-g bind_override-o: bind_override.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) bind_override bind_override-*

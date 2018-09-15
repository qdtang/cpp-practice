override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< redir
@echo ======================OUTPUT======================
@./redir
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: redir-g
	$(run)
	
release: redir-o
	$(run)


redir-g redir-o: redir.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) redir redir-* log

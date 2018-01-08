override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< unevaluatedcontext
@echo ======================OUTPUT======================
@./unevaluatedcontext
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: unevaluatedcontext-g
	$(run)
	
release: unevaluatedcontext-o
	$(run)


unevaluatedcontext-g unevaluatedcontext-o: unevaluatedcontext.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) unevaluatedcontext unevaluatedcontext-*

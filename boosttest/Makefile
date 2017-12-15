override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
@ln -s -f $< boosttest
@echo ======================OUTPUT======================
@./boosttest < email.txt
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: boosttest-g
	$(run)

release: boosttest-o
	$(run)


boosttest-g boosttest-o: boosttest.cpp
	$(CXX) $(CXXFLAGS) $< -lboost_regex -o $@

clean:
	$(RM) boosttest boosttest-*

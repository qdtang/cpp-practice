override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< is_one_of
@echo ======================OUTPUT======================
@./is_one_of
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: is_one_of-g
	$(run)
	
release: is_one_of-o
	$(run)


is_one_of-g is_one_of-o: is_one_of.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) is_one_of is_one_of-*

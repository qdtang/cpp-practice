override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< remove_type
@echo ======================OUTPUT======================
@./remove_type
endef

release: CXXFLAGS += -O2 -s -DNDEBUG
debug: CXXFLAGS += -g

debug: remove_type-g
	$(run)
	
release: remove_type-o
	$(run)


remove_type-g remove_type-o: remove_type.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) remove_type remove_type-*

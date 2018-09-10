override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< variadic_template
@echo ======================OUTPUT======================
@./variadic_template
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: variadic_template-g
	$(run)
	
release: variadic_template-o
	$(run)


variadic_template-g variadic_template-o: variadic_template.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) variadic_template variadic_template-*

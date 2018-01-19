override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< multipacks
@echo ======================OUTPUT======================
@./multipacks
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: multipacks-g
	$(run)
	
release: multipacks-o
	$(run)


multipacks-g multipacks-o: multipacks.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) multipacks multipacks-*

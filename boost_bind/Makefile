override CXXFLAGS += -Wall -Werror
.PHONY: clean debug release

define run
ln -s -f $< boost_bind
@echo ======================OUTPUT======================
@./boost_bind
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: boost_bind-g
	$(run)
	
release: boost_bind-o
	$(run)


boost_bind-g boost_bind-o: boost_bind.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) boost_bind boost_bind-*

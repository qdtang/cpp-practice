override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< enable_enum_flag
@echo ======================OUTPUT======================
@./enable_enum_flag
endef

release: CXXFLAGS += -O2 -s -DNDEBUG
debug: CXXFLAGS += -g

debug: enable_enum_flag-g
	$(run)
	
release: enable_enum_flag-o
	$(run)


enable_enum_flag-g enable_enum_flag-o: enable_enum_flag.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) enable_enum_flag enable_enum_flag-*

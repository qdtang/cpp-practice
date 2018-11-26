override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< visit_variant
@echo ======================OUTPUT======================
@./visit_variant
endef

release: CXXFLAGS += -O2 -s -DNDEBUG
debug: CXXFLAGS += -g

debug: visit_variant-g
	$(run)
	
release: visit_variant-o
	$(run)


visit_variant-g visit_variant-o: visit_variant.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) visit_variant visit_variant-*

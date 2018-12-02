override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f $< filesystem
@echo ======================OUTPUT======================
@./filesystem
endef

release: CXXFLAGS += -O2 -s -DNDEBUG
debug: CXXFLAGS += -g

debug: filesystem-g
	$(run)
	
release: filesystem-o
	$(run)


filesystem-g filesystem-o: filesystem.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ -lstdc++fs

clean:
	$(RM) -r filesystem filesystem-* fs

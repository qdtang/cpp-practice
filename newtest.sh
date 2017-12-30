#!/bin/sh

usage()
{
	echo "usage: $1 <test_name>"
	exit $2
}

if [ $# != 1 ]; then
	usage $0 1
fi

if [ "$1" = "-h" -o "$1" = "--help" ]; then
	usage $0 0
fi


name=$1

mkdir ${name}
cd ${name}

#cpp file skeleton
cat > ${name}.cpp << EOF
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Hello\n";
	return 0;
}
EOF

#Makefile
cat >  Makefile << EOF
override CXXFLAGS += -Wall -Werror -std=c++17
.PHONY: clean debug release

define run
ln -s -f \$< ${name}
@echo ======================OUTPUT======================
@./${name}
endef

release: CXXFLAGS += -O2 -s
debug: CXXFLAGS += -g -DDEBUG

debug: ${name}-g
	\$(run)
	
release: ${name}-o
	\$(run)


${name}-g ${name}-o: ${name}.cpp
	\$(CXX) \$(CXXFLAGS) \$< -o \$@

clean:
	\$(RM) ${name} ${name}-*
EOF

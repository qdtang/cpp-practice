#!/bin/sh

last=10
if [ $# -gt 0 ]; then
	last=$1
fi

output=$(make CXXFLAGS+=-DLAST=${last} 2>&1 | grep prime_number)

num=$(echo "${output}" | wc -l)
echo "${output}" | head -n $((num/2))

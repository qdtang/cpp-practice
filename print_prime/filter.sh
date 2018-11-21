#!/bin/bash

last=10
if [ $# -gt 0 ]; then
	last=$1
fi

output=$(make CXXFLAGS+=-DLAST=${last} |& grep prime_number)

num=$(echo "${output}" | wc -l)
echo "${output}" | head -n $((num/2))

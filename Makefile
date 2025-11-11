

.PHONY: build run test

build: 
	cmake -S . -B build && cmake --build build

run: 
	cmake -S . -B build && cmake --build build && ./build/leetcode


test: 
	cmake -S . -B build && cmake --build build && ./build/tests "[${TAG}]"
#include <iostream>
#include <queue>
#include <cassert>
#include "mylib.h"


void test() {
	std::priority_queue<int> f_queue;
	std::priority_queue<int> s_queue;
	f_queue.push(1);
	f_queue.push(5);
	f_queue.push(15);
	s_queue.push(1);
	s_queue.push(9);
	s_queue.push(15);
	std::priority_queue<int> test_queue = edit(f_queue, s_queue);
	assert(15 == test_queue.top());
	test_queue.pop();
	assert(9 == test_queue.top());
	test_queue.pop();
	assert(5 == test_queue.top());
	test_queue.pop();	
	assert(1 == test_queue.top());
	test_queue.pop();
}

#undef main

int main()
{
	test();
	return 0;
}
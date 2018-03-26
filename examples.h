//
// Created by novafacing on 3/23/18.
//

#ifndef REDFLARE_EXAMPLES_H
#define REDFLARE_EXAMPLES_H

#include <stdlib.h>
#include <stdio.h>
#include <cstddef>
#include <vector>
#include <string>

typedef struct memory_segment { /* <-- This is okay */
	std::size_t address;
	std::vector<std::byte> data;
};

class Example {
	int m;
	protected:
		int ExampleX(std::string a);
	public:
	explicit Example(int m);
	Example();
	
	int ExampleA(int a, int b);
		int ExampleB(int a, int b);
	private:
		int ExampleC(int a, int b);
		int slength(const char * s) const;
		bool operator == (const std::string &s);
	~Example();
};
#endif //REDFLARE_EXAMPLES_H

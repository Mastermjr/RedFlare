//
// Created by novafacing on 3/23/18.
//

#include "examples.h"

Example::Example(int m) : m(m) {
	this->m = m;
}

Example::Example() : m(m) {
	this->m = 0;
}

~Example() {

}

/* <-- always use multi-line comments, never single line '//' style comments. These are non-portable to some systems. */
/*                  v always use char ** argv for clarity. We will be maintaining pointer-based coding constraints. */
int main(int argc, char ** argv) { /* <-- always use same-line open brackets for clarity. This improves readability and line matching.
    /* <-- 4 space equivalent, using tabs, NOT spaces. */
}


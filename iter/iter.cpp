// iter.cpp
#include "include/ensure.h"
#include "iter.h"

using namespace iter;

int main() 
{
	try {
		test_accumulate();
		test_adjacent();
		test_apply();
		test_choose();
		test_concatenate();
		test_constant();
		test_enumerator();
		test_enumerator_counted();
		test_enumerator_end();
		test_enumerator_null();
		test_enumerator_reverse();
		test_expr();
		test_factorial();
		test_fmap();
		test_iterator();
		test_iota();
		test_last();
		test_level();
		test_pick();
		test_pair();
		test_pow();
		test_skip();
		test_take();
		test_where();

	}
	catch (...) {
		return -1;
	}

	return 0;
}
